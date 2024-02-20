/*startup_c
Eng.Alfred Fayez*/

#include "platform_Type.h"
extern int main(void);
extern uint32 _S_DATA;
extern uint32 _E_DATA;
extern uint32 _S_bss;
extern uint32 _E_bss;
extern uint32 _E_text;

void Rest_Handler(void);

void Default_Handler()
{
	Rest_Handler();
}

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void H_fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MM_fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Bus_fault(void) __attribute__((weak, alias("Default_Handler")));
void Usage_fault_Handler(void) __attribute__((weak, alias("Default_Handler")));

//booking 1024 B located by .bss to calculate the top of the stack
static uint32 stack_top[256];

void (* const g_p_fn_vectors[])() __attribute__((section(".vectors"))) 	=
{
	(void (*)()) (stack_top + sizeof(stack_top)),
	&Rest_Handler,
	&NMI_Handler,
 	&H_fault_Handler,
 	&MM_fault_Handler,
 	&Bus_fault,
 	&Usage_fault_Handler
};

void Rest_Handler (void)
{	
	//copy data from ROM to RAM
	uint32 DATA_size = (uint8*)&_E_DATA - (uint8*)&_S_DATA;
	uint8* p_src = (uint8*)&_E_text;
	uint8* p_dst = (uint8*)&_S_DATA;
	for(int i=0;i<DATA_size;i++){
		*((uint8*)p_dst++) = *((uint8*)p_src++);
	}

	//init the .bss with zero
	uint8 bss_size = (uint8*)&_E_bss - (uint8*)&_S_bss;
	p_dst = (uint8*)&_S_bss;
	for(int i=0;i<bss_size;i++){
		*((uint8*)p_dst++) = (uint8)0;
	}

	//jump to main
	main();
}

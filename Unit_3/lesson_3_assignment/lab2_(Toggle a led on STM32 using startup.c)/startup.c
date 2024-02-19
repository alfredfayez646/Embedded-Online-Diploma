/*startup_c
Eng.Alfred Fayez*/

#include "platform_Type.h"
extern int main(void);
extern uint32 _stack_top;
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

uint32 vectors[] __attribute__((section(".vectors"))) 	={
(uint32) &_stack_top,
(uint32) &Rest_Handler,
(uint32) &NMI_Handler,
(uint32) &H_fault_Handler,
(uint32) &MM_fault_Handler,
(uint32) &Bus_fault,
(uint32) &Usage_fault_Handler
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

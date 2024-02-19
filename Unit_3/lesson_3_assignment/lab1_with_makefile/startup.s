@@ Eng. Alfred Fayez
.global reset
reset:
		ldr sp, =stack_top
		bl	main
stop:	b 	stop

ORG 	000H 	;initial starting address
MOV	DPTR,#CC_PATTERNS ;  loads  the  adress  Lookup Table

MOV	P1, #0H
MOV	P3, #0H

START: 	
	MOV 	A,#00H 	; initial value of accumulator
	MOV 	B,A
	MOV 	R0,#0AH ;Register R0 initialized as counter which counts from 10 to 0
LOOP: 
	MOV 	A,B
	INC 	A
	MOV 	B,A
	ACALL   DISPLAY ;
	MOV 	P2,A
	ACALL 	DELAY1 	; calls the delay of the timer
	DEC 	R0	;Counter R0 decremented by 1
	MOV 	A,R0 	; R0 moved to accumulator to check if it is zero in next instruction.
	JZ 	START 	;Checks accumulator for zero and jumps to START. Done to check if counting has been finished.
	SJMP 	LOOP

DELAY1:
	MOV	R5, #250D
	
LABEL:	 
	ACALL   DELAY	
  	ACALL   DELAY
   	ACALL   DELAY
	ACALL   DELAY
	
    DJNZ R5,LABEL
    RET
	
DELAY:
	MOV     R6,#250D
	MOV     R7,#250D
	
LABEL1:
	DJNZ R6,LABEL1
	
LABEL2:	
	DJNZ R7,LABEL2
    RET

DISPLAY:
	MOVC	A,@A+PC ;  adds  the  byte  in A to  the  address  in DPTR and  loads A with  data  present  in  the  r e s u l t a n t  address
	RET

CC_PATTERNS: 
	DB 3FH, 06H, 5BH, 4FH, 66H, 6DH, 7DH, 07H, 7FH, 6FH, 0  

END
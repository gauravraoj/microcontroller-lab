	AREA SUM , CODE , READONLY

ENTRY

START

	MOV R1 , #10 
	MOV R2 , #0 
	
LOOP
	ADD R2 , R2 , R1 
	SUBS R1 , #0X01 
	BNE LOOP 
BACK B BACK 
	END 
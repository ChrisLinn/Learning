CODES SEGMENT
    ASSUME CS:CODES
START:
	MOV DL,31H
	MOV CX,5

L1:
	PUSH DX
	MOV DX,280H
	IN AL,DX
	AND AL,01H
	MOV AH,AL
L2:
	IN AL,DX
	AND AL,01H
	CMP AH,AL
	JZ L2
L3:
	IN AL,DX
	AND AL,01H
	CMP AH,AL
	JNZ L3
	POP DX

	MOV AH,02H
	INT 21H
	INC DL
	LOOP L1
	
	MOV AH,4CH
	INT 21H
CODES ENDS
    END START
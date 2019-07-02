; MONTA TELA:
	LD HL,ESTRELAS ; 7100H 
	XOR A 
	LOOPC: 
	PUSH HL 
	LD D,(HL) 
	LD HL,6144 
	LD B,0 
	LD C,A 
	ADD HL,BC 
	PUSH AF 
	LD E,A 
	XOR A 
LOOPL: 
	PUSH AF 
	LD A,D 
	AND 7 
	BIT 0,E 
	JR Z,BIT0 
	ADD A,8 
BIT0: 
;    LD A,64
	CALL WRTVRM 
	INC D 
	LD C,32 
	ADD HL,BC 
	POP AF 
	INC A 
	CP 24 
	JR NZ,LOOPL 
	POP AF 
	POP HL 
	INC HL 
	INC A 
	CP 32 
	JR NZ,LOOPC 

;XOR A; locate 0,22 ->1,23
	LD A,1
	LD (CSRX),A
	LD A,23
	LD (CSRY),A

	LD B,32   ; print 32 caracteres codigo 196
	LD A,196
LL: 
    CALL CHPUT
	DJNZ LL

	RET

; COPIA DAS POSICOES DE MEMORIA DE 0X7100 A 0X711F 
; USADO PARA GERAR AS ESTRELAS
ESTRELAS:
DEFB 0x6F, 0x75, 0x6E, 0x64, 0x3A, 0x00, 0x53, 0x6B
DEFB 0x69, 0x70, 0x20, 0x3A, 0x00, 0xED, 0x5B, 0x1C
DEFB 0xF4, 0x13, 0x7A, 0xB3, 0xC0, 0xCD, 0x78, 0x66
DEFB 0x21, 0x71, 0xF8, 0x06, 0x06, 0x7E, 0x23, 0xDF


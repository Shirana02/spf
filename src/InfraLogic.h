#ifndef SPF_INFRA_H
	#define SPF_INFRA_H 1

	#define SPF_INST_OPCODE_MOVE 0b00000000
	#define SPF_INST_OPCODE_ADD 0b00010000
	#define SPF_INST_OPCODE_SUB 0b00010001
	#define SPF_INST_OPCODE_TIME 0b00010010
	#define SPF_INST_OPCODE_DIVIDE 0b00010011

	int InitClock(void* textArea);
	int AdvanceClock(void* textArea, void* dataArea);

	typedef const enum{
		NoThanks = 2,
		YesPlease = 1,
		AnotherAnswer,
	} DoYouWant;

#endif

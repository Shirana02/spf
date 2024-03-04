#ifndef SPF_GENERAL_H
	#define SPF_GENERAL_H 1

	#define SPF_TEXT_AREA_SIZE 500000000
	#define SPF_DATA_AREA_SIZE 1499999996
	#define SPF_RETURN_AREA_SIZE 4

	typedef struct _SpfInstruction{
		char prefix;
		char opcode;
//2byte
		void* srcAddr;
		void* dstAddr;
	} SpfInstruction;
#endif

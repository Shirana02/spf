#ifndef SPF_INFRA_ACTIONS_H
	#define SPF_INFRA_ACTIONS_H 1

	#include "InfraLogic.h"

	#define SPF_INST_PREFIX_CHAR 0b00000001
	#define SPF_INST_PREFIX_INT 0b00000010
	#define SPF_INST_PREFIX_UINT 0b00000011
	#define SPF_INST_PREFIX_REAL 0b00000100

	DoYouWant ExecuteInstruction(SpfInstruction *instruction);
#endif

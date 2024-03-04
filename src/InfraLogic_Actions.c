#include "General.h"
#include "InfraLogic.h"
#include "InfraLogic_Actions.h"



#include <stdio.h>


int move(char prefix, void* src, void* dst);
int add(char prefix, void* src, void* dst);

DoYouWant ExecuteInstruction(SpfInstruction *instruction){
	switch(instruction->opcode){
		case SPF_INST_OPCODE_MOVE:
printf("opcode:%c\n", SPF_INST_OPCODE_MOVE + 33);
printf("opcode:%c\n", instruction->opcode + 33);
			move(instruction->prefix, instruction->srcAddr, instruction->dstAddr);
			return YesPlease;
			break;
		case SPF_INST_OPCODE_ADD:
			add(instruction->prefix, instruction->srcAddr, instruction->dstAddr);
			return NoThanks;
			break;
		default:
			return -1;
	}
}

//actions
int move(char prefix, void* src, void* dst){
	switch(prefix){
		case SPF_INST_PREFIX_CHAR:
printf("src:%p\n", src);
printf("dst:%p\n", dst);
			*((char *)dst) = *((char *)src);
			break;
		case SPF_INST_PREFIX_INT:
			*((int *)dst) = *((int *)src);
			break;
		case SPF_INST_PREFIX_UINT:
			*((unsigned int *)dst) = *((unsigned int *)src);
			break;
		case SPF_INST_PREFIX_REAL:
			*((double *)dst) = *((double *)src);
			break;
		default:
			return -1;
	}
	return 1;
}
	
int add(char prefix, void* src, void* dst){
	switch(prefix){
		case SPF_INST_PREFIX_CHAR:
			*((char *)dst) += *((char *)src);
			break;
		case SPF_INST_PREFIX_INT:
			*((int *)dst) += *((int *)src);
			break;
		case SPF_INST_PREFIX_UINT:
			*((unsigned int *)dst) += *((unsigned int *)src);
			break;
		case SPF_INST_PREFIX_REAL:
			*((double *)dst) += *((double *)src);
			break;
		default:
			return -1;
	}
	return 1;
}

#include <unistd.h>
#include <stdio.h>

#include "General.h"
#include "StartupLogic.h"
#include "InfraLogic.h"

int validateArgs(int argc);

int main(int argc, char** argv){
	if( validateArgs(argc) == -1 ){
		return 1;
	}

	//program load
	void* const SPF_TEXT_HEAD = sbrk(SPF_TEXT_AREA_SIZE);
	void* const SPF_DATA_HEAD = sbrk(SPF_DATA_AREA_SIZE);
	void* const SPF_DATA_RETURN_HEAD = sbrk(SPF_RETURN_AREA_SIZE);

	unsigned int loadsize_text = LoadTextArea(argv[1], SPF_TEXT_HEAD);
	unsigned int loadsize_data = LoadDataArea(argv[2], argv[3], SPF_DATA_HEAD);
int hoge;
char* testC = (char *)SPF_TEXT_HEAD;
for(hoge = 0; hoge < 32; hoge++){
	printf("idx = %d  %x\n", hoge, testC[hoge]);
}

	void* const SPF_TEXT_USR_HEAD = SPF_TEXT_HEAD + loadsize_text;
	void* const SPF_DATA_USR_HEAD = SPF_DATA_HEAD + loadsize_data;

	//spf run
	int clockResult = 0;
	clockResult = InitClock(SPF_TEXT_HEAD);
	while( clockResult == 1 ){
printf("!\n");
printf("datathead = %p\n", SPF_DATA_HEAD);
printf("returnhead = %p\n", SPF_DATA_RETURN_HEAD);
		clockResult = AdvanceClock(SPF_TEXT_HEAD, SPF_DATA_HEAD);
printf("!\n");
		if( clockResult < 0 ){
			printf("Assert: SPF crashed!\n");
			return 1;
		}

		//test code!!!!!!!!!!!!!!!
		break;
	}


	SpfInstruction* instP = (SpfInstruction *)SPF_TEXT_HEAD;
	printf("texthead = %p\n", SPF_TEXT_HEAD);
	printf("datathead = %p\n", SPF_DATA_HEAD);
	printf("instruction1: %x %x %p %p\n", instP->prefix, instP->opcode, instP->srcAddr, instP->dstAddr);
	printf("instruction2: %x %x %p %p\n", instP[1].prefix, instP[1].opcode, instP[1].srcAddr, instP[1].dstAddr);

	int *ret = (int *)SPF_DATA_RETURN_HEAD;
	printf("return:%d\n", *ret);
	return *ret;
}

int validateArgs(int argc){
	if(argc < 1){
		printf("error: plese input text, data, and dataAddressMap files.\n");
		return -1;
	}
	else if(argc < 4){
		printf("error: to short input. \nplease input the dataAddressMap file\n.");
		return -1;
	}
	if(4 < argc){
		printf("info: the forth and higher arguments are ignored.");
		return -1;
	}
	return 1;
}

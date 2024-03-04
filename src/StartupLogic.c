#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

#include "General.h"
#include "StartupLogic.h"

int offsetInnerAddress_TextArea(unsigned int dataSize, void* const topAddr);
int offsetInnerAddress_DataArea(char* dataAddrMap_filepath, void* const topAddr);

int LoadTextArea(char* text_filepath, void* topAddr){
	int fd;
	fd = open(text_filepath, O_RDONLY);
	if(fd == -1){
		printf("Error: file open is failed. => TextAreaInput = arg[1]\n");
		return -1;
	}

	int readsize;
	readsize = read(fd, topAddr, SPF_TEXT_AREA_SIZE);
	if(readsize == -1){
		printf("Error: file read is failed. => TextAreaInput = arg[1]\n");
		return -1;
	}

	offsetInnerAddress_TextArea(readsize, topAddr);

	return readsize;
}
		
int LoadDataArea(char* data_filepath, char* dataAddrMap_filepath, void* topAddr){
	int fd_data;
	fd_data = open(data_filepath, O_RDONLY);
	if(fd_data == -1){
		printf("Error: file open is failed. => DataAreaInput = arg[2]\n");
		return -1;
	}

	int readsize_data;
	readsize_data = read(fd_data, topAddr, SPF_DATA_AREA_SIZE);
	if(readsize_data == -1){
		printf("Error: file read is failed. => DataAreanput = arg[2]\n");
		return -1;
	}

	offsetInnerAddress_DataArea(dataAddrMap_filepath, topAddr);

	return readsize_data;
}

int offsetInnerAddress_TextArea(unsigned int dataSize, void* const topAddr){
	SpfInstruction* instructions = (SpfInstruction *)topAddr;
	int instructionNum = dataSize / sizeof(SpfInstruction);

	int i;
	uintptr_t topAddr_int = (uintptr_t)topAddr;
	for(i = 0; i < instructionNum; i++){
printf("src=%p  dst=%p\n", instructions[i].srcAddr, instructions[i].dstAddr);
		instructions[i].srcAddr += topAddr_int;
		instructions[i].dstAddr += topAddr_int;
	}
	return 1;
}
	
int offsetInnerAddress_DataArea(char* dataAddrMap_filepath, void* const topAddr){
	int fd;
	fd = open(dataAddrMap_filepath, O_RDONLY);
	if(fd == -1){
		printf("Error: file open is failed. => DataAddrMapInput = arg[3]\n");
		return -1;
	}

	uintptr_t innerOffsetAddress[1];
	uintptr_t topAddr_int = (uintptr_t)topAddr;
//printf("topAddr_int = %ld\n", topAddr_int);
//printf("topAddr = %p\n", topAddr);
	while( read(fd, innerOffsetAddress, sizeof(void *)) ){
//printf("innerAddr = %ld\n", innerOffsetAddress[0]);
		*((uintptr_t *)(topAddr + innerOffsetAddress[0])) += topAddr_int; 
	}
	
	return 1;
}

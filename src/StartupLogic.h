#ifndef SPF_STARTUP_H
	#define SPF_STARTUP_H 1

	int LoadTextArea(char* text_filepath, void* topAddr);
	int LoadDataArea(char* data_filepath, char* dataAddrMap_filepath, void* topAddr);
#endif

#include "General.h"
#include "InfraLogic.h"
#include "InfraLogic_Actions.h"

static SpfInstruction* ProgramCounter;

int InitClock(void* textArea){
	ProgramCounter = (SpfInstruction *)textArea;
	return 1;
}

int AdvanceClock(void* textArea, void* dataArea){
	DoYouWant doYouWantFetch = ExecuteInstruction(ProgramCounter);
	if(doYouWantFetch == AnotherAnswer){
		return -1;
	}
	if(doYouWantFetch == YesPlease){
		ProgramCounter += 1;
	}
	return 1;
}
			

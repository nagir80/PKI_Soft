//---------------------------------------------------------------------------

#pragma hdrstop

#include "RsvThread.h"
//#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

extern int i;
extern HANDLE mutexObject;

RsvThread::RsvThread(bool susp):TThread(susp){

}

void __fastcall RsvThread::Execute(){
	while(!Terminated){
		i--;
		Sleep(1);
		Synchronize(update);
	}
}

void __fastcall RsvThread::update(){
	// Form1->Label1->Caption = i;
}
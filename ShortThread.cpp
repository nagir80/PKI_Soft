//---------------------------------------------------------------------------

#pragma hdrstop

#include "ShortThread.h"
//#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ShortThread::ShortThread(bool susp,
							void (*t_func)(),
							void (*upd_func)()):TThread(susp), t_func(t_func), upd_func(upd_func){

}
void __fastcall ShortThread::Execute(){
	while(!Terminated){
        t_func();
		Sleep(1000);

		Synchronize(update);
	}
}
void __fastcall ShortThread::update(void){
    upd_func();
}

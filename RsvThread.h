//---------------------------------------------------------------------------

#ifndef RsvThreadH
#define RsvThreadH
#include <vcl.h>

class RsvThread : public TThread{
public:
	RsvThread(bool susp);
	void __fastcall Execute();
	void __fastcall update(void);
};
//---------------------------------------------------------------------------
#endif

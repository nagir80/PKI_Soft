//---------------------------------------------------------------------------

#ifndef ShortThreadH
#define ShortThreadH
#include <vcl.h>
#include <string>
//---------------------------------------------------------------------------
#endif

class ShortThread : public TThread {
	void (*t_func)();
	void (*upd_func)();

public:
	ShortThread(bool susp,
		void (*t_func)(),
		void (*upd_func)());
	void __fastcall Execute();
	void __fastcall update(void);

};

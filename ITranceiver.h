//---------------------------------------------------------------------------

#ifndef ITranceiverH
#define ITranceiverH
#include "main_incl.h"
#include <windows.h>
#include "ISettings.h"
//#include "main_pp.h"



 class ITranceiver{
	ISettings* i_set;
	int result;

	friend DWORD WINAPI ThreadProc(LPVOID lpParameter); // пояснения см. ниже
	friend DWORD WINAPI ThreadProc2(LPVOID lpParameter); //
 public:
	char bufrd[1024];      // буфер приема
	unsigned short rd_in;
	unsigned short rd_out;
	short size_rd;
	char bufwr[1024];        //буфер передачи
	unsigned short wr_in;
	unsigned short wr_out;
	short size_wr;

	void addResult(int i){ result += i;}
	int getResult(void) {return result;}

	ITranceiver(ISettings* i_set);
	~ITranceiver();

	BOOL ExecuteTr();
	BOOL ExecuteRsv();
	HANDLE getTrHandle() { return m_hThread2;}
	HANDLE getRsvHandle() { return m_hThread;}




 protected:
	DWORD m_dwID;
    DWORD m_dwID2;

	virtual DWORD rsvThreadFunc()=0; // эта функция будет переопределяться в наследующих классах
	virtual DWORD trThreadFunc()=0; // эта функция будет переопределяться в наследующих классах
	HANDLE m_hThread;
	HANDLE m_hThread2;
 };


extern DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
			ITranceiver *pRsvThread=(ITranceiver *)lpParameter;
			return pRsvThread->rsvThreadFunc();
}

extern DWORD WINAPI ThreadProc2(LPVOID lpParameter)
{
			ITranceiver *pTrThread=(ITranceiver *)lpParameter;
			return pTrThread->trThreadFunc();
}


//---------------------------------------------------------------------------
#endif

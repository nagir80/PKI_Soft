//---------------------------------------------------------------------------

#pragma hdrstop

#include "ITranceiver.h"

ITranceiver::ITranceiver(ISettings* i_set):i_set(i_set){
	 result = 0;
	 size_rd = 0;
	 size_wr = 0;
	 rd_in = 0;
	 rd_out = 0;
	 wr_in = 0;
	 wr_out = 0;
	 m_hThread=NULL;
	 m_hThread2=NULL;
}




ITranceiver::~ITranceiver()
{    if (m_hThread) {
		 CloseHandle(m_hThread);
	 }
	 if (m_hThread2) {
		 CloseHandle(m_hThread2);
	 }
}



BOOL ITranceiver::ExecuteTr()
{
			if (m_hThread2)
			{
						return FALSE;
			}
			m_hThread2=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE) ThreadProc2,this,CREATE_SUSPENDED,&m_dwID2);

	return (m_hThread2==NULL)?FALSE:TRUE;

}

BOOL ITranceiver::ExecuteRsv()
{
			if (m_hThread)
			{
						return FALSE;
			}
			m_hThread=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE) ThreadProc,this,0,&m_dwID);

	return (m_hThread==NULL)?FALSE:TRUE;

}

//---------------------------------------------------------------------------
#pragma package(smart_init)


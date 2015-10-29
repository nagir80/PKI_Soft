//---------------------------------------------------------------------------

#ifndef BINRProtocolH
#define BINRProtocolH
#include "IProtocol.h"
//#include "StendData.h"

class TTestBINRProtocol;

class BINRProtocol : public IProtocol{

public:
	BINRProtocol();
	//DataPKI* _DP;
	int code (char* buf);
	void decode (char* buf);
	void check_values(char* buf_,int& index_);
	void formCRC(char* buf);

};
//---------------------------------------------------------------------------
#endif

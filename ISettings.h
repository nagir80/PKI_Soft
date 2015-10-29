//---------------------------------------------------------------------------

#ifndef ISettingsH
#define ISettingsH

#include "IProtocol.h"

enum ID {SERIAL, LAN};
class  ISettings{
	ID id_type;
protected:
	IProtocol* prt;
public:
	ISettings(IProtocol* prt, ID id_type);
	ID getID();
    IProtocol* getPrt(){return prt;}
	virtual char* print(void)=0;
};
//---------------------------------------------------------------------------
#endif

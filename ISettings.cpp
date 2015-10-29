//---------------------------------------------------------------------------

#pragma hdrstop

#include "ISettings.h"
//ISettings
ISettings::ISettings(IProtocol* prt, ID id_type):id_type(id_type), prt(prt){

	std::cout << "Settings ";
};

ID ISettings::getID(){
	return id_type;
 }


//---------------------------------------------------------------------------
#pragma package(smart_init)

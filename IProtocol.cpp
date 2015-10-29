//---------------------------------------------------------------------------

#pragma hdrstop

#include "IProtocol.h"

IProtocol::IProtocol(){
 //	bc_data = new BinCharData();
	std::cout << "Protocol ";
	in = 0;
	out = 0;
	for (int i = 0; i < 16; i++) {
	   queueMsgs[i] = 0;

	}
	b_wr = new BCD_Wrap();


}

//void IProtocol::set_bc_data(BinCharData* bc) {
 //	bc_data = bc;
//}
//---------------------------------------------------------------------------
#pragma package(smart_init)

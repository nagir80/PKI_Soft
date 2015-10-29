//---------------------------------------------------------------------------

#pragma hdrstop

#include "RTCMProtocol.h"

RTCMProtocol::RTCMProtocol(){
	std::cout << "RTCM ";
}

int RTCMProtocol::code(char* buf){

}
void RTCMProtocol::decode(char* buf){

}
void RTCMProtocol::ConstrValue(char* buf, unsigned int Value, unsigned char NumWord, unsigned char FirstBit, unsigned char NumBits)
{   union
	{   unsigned char c[4];
		unsigned int l;
	} Word, Mask;

	Mask.l = ~((0xFFFFFFFFL << (32 - NumBits)) >> (8 + FirstBit));
	Word.l = (Value << (32 - NumBits)) >> (8 + FirstBit);
	for (signed char i = 0; i < 3; i++)
	{   buf[(NumWord - 1) * 3 + i] &= Mask.c[2 - i];
		buf[(NumWord - 1) * 3 + i] |= Word.c[2 - i];
	}
}

//---------------------------------------------------------------------------
#pragma package(smart_init)

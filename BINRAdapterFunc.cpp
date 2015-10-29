//---------------------------------------------------------------------------

#pragma hdrstop

#include "BINRAdapterFunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include "BinCharData.h"
#include "StendData.h"

extern DataPKI* DP;


void form_76(BinCharData *bchar_data){
   bchar_data->add_data((char)DP->pack_76.modePKI_1);
   bchar_data->add_data((int)DP->pack_76.speedPKI_1);
   bchar_data->add_data((char)DP->pack_76.modePKI_2);
   bchar_data->add_data((int)DP->pack_76.speedPKI_2);
}

void form_7C_1(BinCharData *bchar_data){
	 //ËÀÂÐ
	 bchar_data->add_data((unsigned char)DP->pack_7C.timeMSS_1);
}

void form_7C_2(BinCharData *bchar_data){
	 //ËÀÂÐ
	 bchar_data->add_data((unsigned char)DP->pack_7C.timeMSS_2);
}

void form_7C_3(BinCharData *bchar_data){
	 //ËÀÂÐ
	 bchar_data->add_data((unsigned char)DP->pack_7C.regFind_1);
	 bchar_data->add_data((unsigned char)DP->pack_7C.freqNum_1);
	 bchar_data->add_data((unsigned char)DP->pack_7C.rateNum_1);
}

void form_7C_4(BinCharData *bchar_data){
	 //ËÀÂÐ
	 bchar_data->add_data((unsigned char)DP->pack_7C.regFind_2);
	 bchar_data->add_data((unsigned char)DP->pack_7C.freqNum_2);
	 bchar_data->add_data((unsigned char)DP->pack_7C.rateNum_2);
}


void form_7D(BinCharData *bchar_data){
	 //ËÀÂÐ
	 bchar_data->add_data((unsigned char)DP->pack_7D.timeSink);
}

void form_7E(BinCharData *bchar_data){
	 //ËÀÂÐ
	 bchar_data->add_data((unsigned char)DP->pack_7E.issuing_interval);
	 bchar_data->add_data((unsigned char)DP->pack_7E.left_boundary);
	 bchar_data->add_data((unsigned char)DP->pack_7E.right_border);
	 bchar_data->add_data((unsigned char)DP->pack_7E.across);
}

void form_7F(BinCharData *bchar_data){
	 //ËÀÂÐ
	 bchar_data->add_data((unsigned char)DP->pack_7F.comCode);
}
//---------------------------------------------------------------------------

#pragma hdrstop
#include <string>

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <systypes.h>
#include <stdint.h>

#include "StendData.h"
#include "BINRProtocol.h"
//#include "main.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)


DataPKI::DataPKI(int* speed_rec_,int* speed_mod_,int mss1_,int mss2_,int click_rate1_,int click_rate2_,int frequency1,int frequency2,int speed1,int speed2){
   //���� !!!!   ������������������� ��������� DataPKI ���������� ����������
   pack_76.modePKI_1 = 1;
   pack_76.speedPKI_1 = speed_rec_[0];
   pack_76.modePKI_2 = 1;
   pack_76.speedPKI_2 = speed_rec_[1];
   pack_7C.timeMSS_1 = (unsigned char)mss1_;
   pack_7C.timeMSS_2 = (unsigned char)mss2_;
   pack_7C.regFind_1 = (unsigned char)click_rate1_;
   pack_7C.regFind_2 = (unsigned char)click_rate2_;
   pack_7C.freqNum_1 = (unsigned char)frequency1;
   pack_7C.freqNum_2 = (unsigned char)frequency2;
   pack_7C.rateNum_1 = (unsigned char)speed1;
   pack_7C.rateNum_2 = (unsigned char)speed2;
}

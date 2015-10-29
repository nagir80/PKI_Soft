//---------------------------------------------------------------------------
#ifndef RTCMProtocolH
#define RTCMProtocolH
#include "IProtocol.h"
//#include "StendData.h"

class RTCMdata{

public:
   class Header{
	  public:
	  unsigned char preamble;   //  8
	  unsigned char mID;        //  6
	  unsigned short sID;       // 10

	  unsigned short modZCnt;   // 13
	  unsigned char seqN;       //  3
	  unsigned char dataWrd;    //  5
	  unsigned char health;     //  3
   } hdr;

   class Msg1_9{
	  unsigned char quantSat;
	  struct
	  {   unsigned char scale;  //  1
		  unsigned char udre;   //  2
		  unsigned char id;     //  5
		  signed short prc;     //  16
		  signed short    rrc;  //  8
		  unsigned char iod;    //  8
	  } satellite[24];
   } message1_9;
};


class RTCMProtocol : public IProtocol{
   RTCMdata *rcmData;
   void ConstrValue(char* buf, unsigned int Value, unsigned char NumWord, unsigned char FirstBit, unsigned char NumBits);
public:
   RTCMProtocol();
   int code (char* buf);
   void decode (char* buf);

};


//---------------------------------------------------------------------------
#endif

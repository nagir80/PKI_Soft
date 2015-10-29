//---------------------------------------------------------------------------

#ifndef IProtocolH
#define IProtocolH
#include "main_incl.h"
//#include "StendData.h"
#include "BinCharData.h"
#include "BCD_Wrap.h"
#include <map>


enum PROT {RTCM, BINR};
class  IProtocol{
	PROT prt;

protected:
//	BinCharData *bc_data;
	BCD_Wrap * b_wr;
	unsigned short queueMsgs[16];
	unsigned short in;
	unsigned short out;

public:
	IProtocol();
	virtual int code (char* buf) = 0;
	virtual void decode (char* buf) = 0;
    BCD_Wrap* get_bwr(){return b_wr;}
//	void set_bc_data(BinCharData* bc);



	void add_msg (unsigned short msgNum){
	   queueMsgs[in&0xF] = msgNum;

	   in++;
	}
	bool is_msg (){
	   if (in != out) return true;
	   else return false;
	}
	unsigned short get_msg(){
		if (out != in){
		   out ++;
		   return (queueMsgs[(out-1)&0xF]);
		}
		return 0xFFFF; // нет новых сообщений
	}


};

//---------------------------------------------------------------------------
class RR : public IProtocol{
int hh;
public:
int gg;
};
#endif

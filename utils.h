#ifndef _UTILS_H_
#define _UTILS_H_

#include "COMTranceiver.h"

class TestClass
{   public: static void convert(char i, char* res);
			static void convert(short i, char* res);
			static void convert(int i, char* res);
			static void convert(float i, char* res);
			static void convert(double i, char* res);
};

class Utils{
public:
	static int baudesToInt(BAUD baud);
	static BAUD intToBaudes(int baud);
	static BAUD indexToBaudes(int index);
	static int indexToBaudes1(int index1);

	static int dbToInt(DATA_BITS db);
	static DATA_BITS intToDb(int db);
	static DATA_BITS indexToDb(int index);
    static int indexToDb1(int index__);

	static int parToInt(PARITY par);
	static PARITY intToPar(int par);
	static PARITY indexToPar(int index);

	static int sbToInt(STOP_BITS sb);
	static STOP_BITS intToSb(int sb);
	static STOP_BITS indexToSb(int index);

	static int fcToInt(FLOW_CTR fc);
	static FLOW_CTR intToFc(int fc);
	static FLOW_CTR indexToFc(int index);

};

#endif
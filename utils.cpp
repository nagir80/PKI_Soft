

#include "utils.h"




void TestClass::convert(char i,char* res)
{   memcpy(res, (char*)&i, 1);
}

void TestClass::convert(short i, char* res)
{   memcpy(res, (char*)&i, 2);
}

void TestClass::convert(int i, char* res)
{   memcpy(res, (char*)&i, 4);
}

void TestClass::convert(float i, char* res)
{   memcpy(res, (char*)&i, 4);
}

void TestClass::convert(double i, char* res)
{   memcpy(res, (char*)&i, 8);
}


int Utils::baudesToInt(BAUD baud){
	return (int) baud;
}
BAUD Utils::intToBaudes(int baud){
	return (BAUD) baud;
}

BAUD Utils::indexToBaudes(int index){
	switch (index){
	case 0:
		return BR_600;
		break;
	case 1:
		return BR_1200;
		break;
	case 2:
		return BR_2400;
		break;
	case 3:
		return BR_4800;
		break;
	case 4:
		return BR_9600;
		break;
	case 5:
		return BR_14400;
		break;
	case 6:
		return BR_19200;
		break;
	case 7:
		return BR_38400;
		break;
	case 8:
		return BR_57600;
		break;
	case 9:
		return BR_115200;
		break;
	default:
		return BR_600;
		break;
	}
}
int Utils::indexToBaudes1(int index1)
{   switch (index1)
		  {   case 600:
						 return 0;
						 break;
			  case 1200:
						 return 1;
						 break;
			  case 2400:
						 return 2;
						 break;
			  case 4800:
						 return 3;
						 break;
			  case 9600:
						 return 4;
						 break;
			  case 14400:
						 return 5;
						 break;
			  case 19200:
						 return 6;
						 break;
			  case 38400:
						 return 7;
						 break;
			  case 57600:
						 return 8;
						 break;
			  case 115200:
						 return 9;
						 break;
			  default:
						 return 0;
						 break;
		 }
}

int Utils::dbToInt(DATA_BITS db){
	switch (db){
	case DB_5:
		return 5;
		break;

	case DB_6:
		return 6;
		break;

	case DB_7:
		return 7;
		break;

	case DB_8:
		return 8;
		break;

	case DB_9:
		return 9;
		break;

	default:
		return 8;
		break;
	}
}

DATA_BITS Utils::intToDb(int db){

	return (DATA_BITS)db;
}
DATA_BITS Utils::indexToDb(int index){

	switch (index){
	case 0:
		return DB_5;
		break;

	case 1:
		return DB_6;
		break;

	case 2:
		return DB_7;
		break;

	case 3:
		return DB_8;
		break;

	case 4:
		return DB_9;
		break;

	default:
		return DB_8;
		break;
	}
}

int Utils::indexToDb1(int index__){

	switch (index__){
	case 5:
		return 0;
		break;

	case 6:
		return 1;
		break;

	case 7:
		return 2;
		break;

	case 8:
		return 3;
		break;

	case 9:
		return 4;
		break;

	default:
		return 3;
		break;
	}
}

int Utils::parToInt(PARITY par){
	switch (par){
	case PAR_NONE:
		return 0;
		break;
	case PAR_ODD:
		return 1;
		break;
	case PAR_EVEN:
		return 2;
		break;
	default:
		return -1;
		break;


	}
}
PARITY Utils::intToPar(int par){
	return (PARITY)par;
}

PARITY Utils::indexToPar(int index){
	switch (index){
	case 0:
		return PAR_NONE;
		break;
	case 1:
		return PAR_ODD;
		break;
	case 2:
		return PAR_EVEN;
		break;
	default:
		return PAR_NONE;
		break;


	}
}

int Utils::sbToInt(STOP_BITS sb){
	return (int) sb;
}
STOP_BITS Utils::intToSb(int sb){
	return (STOP_BITS) sb;
}

STOP_BITS Utils::indexToSb(int index){
	switch (index){
		case 0:
			return SB_ONE;
			break;
		case 1:
			return SB_ONE_HALF;
			break;
		case 2:
			return SB_TWO;
			break;
		default:
			return SB_ONE;
			break;
	}
}


int Utils::fcToInt(FLOW_CTR fc){
	switch (fc){
		case FC_NONE:
				return 0;
			break;
		case FC_XON:
			return 2;
			break;
		case FC_CTS:
			return 1;
			break;
		default:
			return -1;
			break;


	}
}
FLOW_CTR Utils::intToFc(int fc){
	return (FLOW_CTR)fc;
}

FLOW_CTR Utils::indexToFc(int index){
	switch (index){
	case 0:
		return FC_NONE;
		break;
	case 1:
		return FC_XON;
		break;
	case 2:
		return FC_CTS;
		break;
	default:
		return FC_NONE;
		break;
	}
}


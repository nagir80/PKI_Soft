//---------------------------------------------------------------------------

#ifndef BinFileReaderH
#define BinFileReaderH

#include <string>
#include "IConverter.h"
#include "IFileReader.h"
#include "COMTranceiver.h"

#include "IProtocol.h"

#include <vector>
#include <System.Classes.hpp>


class BinFileReader: public IFileReader{
private:


 //			 char* filename;
	public:
			 void set_param(char,int* st,int val){};
			 int open_bin_f(int);
			 BinFileReader(char*);
			 ~BinFileReader();
			 void clean_stor(int);
			 int get_value() {};
			 void set_st(int){};
};
//---------------------------------------------------------------------------
#endif

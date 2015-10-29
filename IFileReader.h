//---------------------------------------------------------------------------

#ifndef IFileReaderH
#define IFileReaderH
#include <string>
#include "COMTranceiver.h"
//#include "main_pp.h"

#include <vector>

class IFileReader
{
  protected:
  			 FILE* fb;
			 unsigned int count;
 			 unsigned int readed;   // Количество прочитанных символов.
			 bool key;
			 std::vector <char> bin;
			 unsigned int bin_size;


	public:
			 virtual char getBinChar(unsigned int index){ return bin[index];}
			 virtual void clrBin(void){bin.clear();}
			 virtual void addBinChar(char c){bin.push_back(c);}
			 virtual void set_size(unsigned int ui){bin_size = ui;}
			 virtual int open_bin_f(int)=0;
			 virtual void set_param(char,int*,int)=0;
			 virtual void clean_stor(int) = 0;
			 virtual int get_value() = 0;
			 virtual void set_st(int) = 0;
			 void set_readed(unsigned int);

			 IFileReader(){};
			 IFileReader(char*);
			 ~IFileReader(){};
			 bool openfile(){ return key; }
			 virtual int get_size(){return bin_size;}
			 virtual int get_buf(char* buf);
};
//---------------------------------------------------------------------------
#endif

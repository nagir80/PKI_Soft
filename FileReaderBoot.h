//---------------------------------------------------------------------------

#ifndef FileReaderBootH
#define FileReaderBootH

#include "IFileReaderWrap.h"

class FileReaderBoot : public IFileReaderWrap{
private:
//	IFileReader* ifr;
	char command;
	int* storage;
	unsigned int value;
public:
	FileReaderBoot(IFileReader* ifr/*, char* filename*/);
	int open_bin_f(int);
	int get_buf(char* buf);
	int get_size();
	char getBinChar(unsigned int index);
	void clrBin(void);
	void addBinChar(char c);
	void set_size(unsigned int ui);
	void set_param(char,int*,int);
	void clean_stor(int);
	//short get_st(void){return storage;}
	void set_st(int ind_){storage = new int[ind_];}
		int* st(void){return storage;}
	~FileReaderBoot();
	int get_value(){ return value; }


};
//---------------------------------------------------------------------------
#endif

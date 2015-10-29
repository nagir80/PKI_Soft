//---------------------------------------------------------------------------

#pragma hdrstop

#include "FileReaderBoot.h"
//#include "main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

FileReaderBoot::FileReaderBoot(IFileReader* ifr/*, char* filename*/):IFileReaderWrap(ifr)/*, ifr(ifr)*/{

}

int FileReaderBoot::open_bin_f(int size){

	int val = 0;
	ifr->addBinChar(command);
	if(*(st()))
	{
	   for(int i = 0; i < value; i++)
		{   val = storage[i];
			ifr->addBinChar((unsigned char)val);
			ifr->addBinChar((unsigned char)(val>>8));
			ifr->addBinChar((unsigned char)(val>>16));
			ifr->addBinChar((unsigned char)(val>>24));
		}
	  //	ifr->set_readed(value);
	}

	if (ifr->open_bin_f(size) < 0) {
	  ifr->clrBin();
	  ifr->set_size(0);
	  return -1;
	}


	set_size(get_size() + value*4 + 1);
 	//set_size(get_size()+value);
	return get_size();

}



int FileReaderBoot::get_buf(char* buf){
	return ifr->get_buf(buf);
}
int FileReaderBoot::get_size(){
	return ifr->get_size();
}
char FileReaderBoot::getBinChar(unsigned int index){
	return ifr->getBinChar(index);
}

void FileReaderBoot::addBinChar(char c){
	ifr->addBinChar(c);
}

void FileReaderBoot::set_size(unsigned int ui){
	ifr->set_size(ui);
}

void FileReaderBoot::clrBin(void){
	ifr->clrBin();
}

//------------------------------------------------------------------------------
void FileReaderBoot::set_param(char command_,int* st_,int val_)
{   for(int i = 0; i <= val_; i++)
	   storage[i] = st_[i];
	value = val_;
	command = command_;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

FileReaderBoot::~FileReaderBoot()
{   delete[]storage;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void FileReaderBoot::clean_stor(int ind_)
{   for(int i = 0; i <= ind_; i++)
		storage[i] = 0;
}

//---------------------------------------------------------------------------

#pragma hdrstop

#include "IFileReader.h"
//#include "main.h"
#include "COMTranceiver.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

 IFileReader::IFileReader(char* filename): readed(0), bin_size(0)
{   count = 0;
	if((fb = fopen(filename,"rb")) != NULL)
	{   while(fgetc(fb) != EOF) ++count;
		key = true;
		rewind(fb);
//      	Form1->Memo1->Lines->Add("File Opened: " + IntToStr((int)count));
	}
	else
		key = false;


}

int IFileReader::get_buf(char* buf){
   int i=0;
  // for (std::vector<char*>::iterator it = bin.begin() ; it != bin.end(); ++it){
  for (int j = 0; j < get_size() ; j++) {
	  buf[i++] =  bin[j];
   }
   bin.clear();
   bin_size = 0;
   return i;

}
void IFileReader::set_readed(unsigned int readed__)
{
	readed = count - readed__;
}

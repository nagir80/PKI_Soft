//---------------------------------------------------------------------------

#pragma hdrstop

#include "BinFileReader.h"
//#include "main.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib>
//------------------------------------------------------------------------------
int BinFileReader::open_bin_f(int value_bin)
{  if (count <= readed) return -1;
   while( bin_size  <= value_bin)
   {   //bufwr__[index] = fgetc(fb);
	   bin.push_back(fgetc(fb));
	   bin_size ++;
	   readed ++;
	   if ((readed == count)||(bin_size == value_bin)) {
		   return bin_size;
	   }
   }

//   return 0;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
BinFileReader::BinFileReader(char* filename):IFileReader(filename)
{
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
BinFileReader::~BinFileReader()
{  fclose(fb);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void BinFileReader::clean_stor(int ind_)
{

}
//------------------------------------------------------------------------------
#pragma package(smart_init)



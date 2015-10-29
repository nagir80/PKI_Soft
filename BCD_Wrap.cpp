//---------------------------------------------------------------------------

#pragma hdrstop

#include "BCD_Wrap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

BCD_Wrap::BCD_Wrap(){
   map_Wrap = new std::map<unsigned short, BinCharData*>();
   map_func = new std::map<unsigned short, void(*)(BinCharData*)>();
}

void BCD_Wrap::add(unsigned short key, void(*ptr)(BinCharData*)){

   (*map_func)[key] =  ptr;
   BinCharData* bcd = new BinCharData();
   (*map_func)[key](bcd);
   (*map_Wrap)[key] =  bcd;
}

void BCD_Wrap::update_data(unsigned short key){


}


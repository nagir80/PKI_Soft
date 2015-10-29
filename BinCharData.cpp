//---------------------------------------------------------------------------

#pragma hdrstop

#include "BinCharData.h"
//#include "StendData.h"
#include "utils.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

BinCharData::BinCharData(){
   data = new std::vector<RecData>();
//   data_in_it = new std::vector<RecData>::iterator(data->begin());
//   data_out_it = new std::vector<RecData>::iterator(data->begin());
   data_in_it=0;
   data_out_it=0;

   cur_size = 0;
   //max_size = size;
}


void BinCharData::add_data(char in){
   char hlp[10] = {0};
   TestClass::convert(in, hlp);
   RecData *rd =  new RecData(hlp, 8);
   data->push_back(*rd);
   data_in_it++;
   int i = data->capacity();
}

void BinCharData::add_data(short in){
   char hlp[10] = {0};
   TestClass::convert(in, hlp);
   RecData *rd =  new RecData(hlp, 16);
   data->push_back(*rd);
   data_in_it++;
	  int i = data->capacity();
}

void BinCharData::add_data(int in){
   char hlp[10] = {0};
   TestClass::convert(in, hlp);
   RecData *rd =  new RecData(hlp, 32);
   data->push_back(*rd);
   data_in_it++;
	  int i = data->capacity();
}

void BinCharData::add_data(float in){
   char hlp[10] = {0};
   TestClass::convert(in, hlp);
   RecData *rd =  new RecData(hlp, 32);
   data->push_back(*rd);
   data_in_it++;
	  int i = data->capacity();
}

void BinCharData::add_data(double in){
   char hlp[10] = {0};
   TestClass::convert(in, hlp);
   RecData *rd =  new RecData(hlp, 64);
   data->push_back(*rd);
   data_in_it++;
      int i = data->capacity();
}

RecData BinCharData::get_data(void){
   data_out_it++;
   return data->at(data_out_it-1);

}

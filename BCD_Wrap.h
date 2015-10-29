//---------------------------------------------------------------------------

#ifndef BCD_WrapH
#define BCD_WrapH
#include <map>
#include "BinCharData.h"

class BCD_Wrap{


public:
   std::map<unsigned short, BinCharData*> *map_Wrap;
   std::map<unsigned short, void(*)(BinCharData*)>  *map_func ;

   BCD_Wrap();
   void add(unsigned short key, void(*ptr)(BinCharData*));
   BinCharData* get_data(unsigned short key){return (*map_Wrap)[key];}
   //void get_func(unsigned short key,BinCharData* bc){(*map_func)[key](bc);}
   void update_data(unsigned short key);
   static int i;
};
//---------------------------------------------------------------------------
#endif




//---------------------------------------------------------------------------

#ifndef BinCharDataH
#define BinCharDataH
#include <vector>
#include <iterator>
#include <string>
#include <math.h>



class RecData {
public:
   char field[10];
   int bits_ct;
   RecData(char *fld="", int bc=0){
	  memcpy(field, fld, ceil((float)bc/4));
	  bits_ct = bc;
   }
};

class BinCharData{
private:
	std::vector<RecData> *data;
//	std::vector<RecData>::iterator *data_in_it;
//	std::vector<RecData>::iterator *data_out_it;
   int data_in_it;
   int data_out_it;
//	std::vector<int, int>::iterator *bits_iterator;

	int index;
//	int max_size;
	int cur_size;
	int cur_start;

public:
   BinCharData();
   void add_data(char in);
   void add_data(short in);
   void add_data(int in);
   void add_data(float in);
   void add_data(double in);

   void reset_data(void){}

   RecData get_data(void);
};

//---------------------------------------------------------------------------
#endif

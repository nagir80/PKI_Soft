//---------------------------------------------------------------------------

#pragma hdrstop

#include "BINRProtocol.h"
//#include "StendData.h"


BINRProtocol::BINRProtocol(){
	std::cout << "BINR ";
}

int BINRProtocol::code (char* buf){
unsigned short num_hlp = 0;
//char* adress = buf;
int index = 0;
RecData rd1;
	if(is_msg())
	   num_hlp = (get_msg());

	buf[index++] = 0x10;
	switch((num_hlp)&0xFF)
	{   case 0x76:   buf[index++] = (num_hlp&0xFF);
					 rd1 = get_bwr()->get_data(num_hlp)->get_data();
					 memcpy(&buf[index++], rd1.field, 1);
					 rd1 = get_bwr()->get_data(num_hlp)->get_data();
					 memcpy(&buf[index], rd1.field, 4);
					 index+=4;
					 rd1 = get_bwr()->get_data(num_hlp)->get_data();
					 memcpy(&buf[index++], rd1.field, 1);
					 rd1 = get_bwr()->get_data(num_hlp)->get_data();
					 memcpy(&buf[index], rd1.field, 4);
					 index+=4;
					 break;

		case 0x7C:   buf[index++] = (num_hlp&0xFF);
					 buf[index++] = ((num_hlp>>8)&0xFF);
					 switch ((num_hlp>>8)&0xFF)
					 {   case 0x1:   rd1 = get_bwr()->get_data(num_hlp)->get_data();
									 memcpy(&buf[index++], rd1.field, 1);
									 break;

						 case 0x2:   rd1 = get_bwr()->get_data(num_hlp)->get_data();
									 memcpy(&buf[index++], rd1.field, 1);
									 break;

						 case 0x3:   rd1 = get_bwr()->get_data(num_hlp)->get_data();
									 memcpy(&buf[index++], rd1.field, 1);
									 rd1 = get_bwr()->get_data(num_hlp)->get_data();
									 memcpy(&buf[index++], rd1.field, 1);
									 rd1 = get_bwr()->get_data(num_hlp)->get_data();
									 memcpy(&buf[index++], rd1.field, 1);
									 break;

						 case 0x4:   rd1 = get_bwr()->get_data(num_hlp)->get_data();
									 memcpy(&buf[index++], rd1.field, 1);
									 rd1 = get_bwr()->get_data(num_hlp)->get_data();
									 memcpy(&buf[index++], rd1.field, 1);
									 rd1 = get_bwr()->get_data(num_hlp)->get_data();
									 memcpy(&buf[index++], rd1.field, 1);
									 break;
					  }
					  break;

		 case 0x7B:   buf[index++] = (num_hlp&0xFF);
					  rd1 = get_bwr()->get_data(num_hlp)->get_data();
					  memcpy(&buf[index++], rd1.field, 1);
					  break;

		 case 0x7D:   buf[index++] = (num_hlp&0xFF);
					  rd1 = get_bwr()->get_data(num_hlp)->get_data();
					  memcpy(&buf[index++], rd1.field, 1);
					  break;

		 case 0x7E:   buf[index++] = (num_hlp&0xFF);
					  rd1 = get_bwr()->get_data(num_hlp)->get_data();
					  memcpy(&buf[index++], rd1.field, 1);
					  rd1 = get_bwr()->get_data(num_hlp)->get_data();
					  memcpy(&buf[index++], rd1.field, 1);
					  rd1 = get_bwr()->get_data(num_hlp)->get_data();
					  memcpy(&buf[index++], rd1.field, 1);
					  rd1 = get_bwr()->get_data(num_hlp)->get_data();
					  memcpy(&buf[index++], rd1.field, 1);
					  break;

		 case 0x7F:   buf[index++] = (num_hlp&0xFF);
					  rd1 = get_bwr()->get_data(num_hlp)->get_data();
					  memcpy(&buf[index++], rd1.field, 1);
					  break;
	}
	check_values(buf,index);
	buf[index++] = 0x10;
	buf[index++] = 0x3;
	return index;
}

void BINRProtocol::decode (char* buf){

}

void BINRProtocol::formCRC(char* buf){

}

void BINRProtocol::check_values(char* buf_,int& index_)
{   char mas[20] = {0}; // Хранит непроверенные символы.
	int must = 0; // Кол.символов котор. нужно проверить
	int already = 0; // Кол символов вкл. 0x10.  0x10
	int already_pl = 0; // Остановка на 0x10
	int already_2pl = 0; // Остановка на след. символе за 0x10
	int already_3pl = 0; // Остановка на след. символе за 0x10 0x10
	int value = index_ - 2; // Кол.символов за исключением 2-х предыдущих.
	int count = 2; // Индекс. 2 - Отсчёт сразу за служебными символами.


	while(1)
	{   if(buf_[count] == 0x10)
		{  already++;
		   already_pl = already + 1;
		   already_2pl = already_pl + 1;
		   already_3pl = already_2pl + 1;
		   must = value - already; // Вычисляем кол-во оставшихся для проверки символов.
		   for(int a = 0,b = already_2pl; a < must; a++,b++) //  непроверенные символы в mas
			  mas[a] = buf_[b];

		   buf_[already_2pl] = 0x10; // Установка 0x10 за 0x10.
		   index_++;
		   already++; // Добавили в кол-во ещё один 0x10
		   value++; // Общее кол-во символов прибавилось на 1.
		   for(int c = 0,d = already_3pl; c < must; c++,d++) // Заносим обратно в buf_
			  buf_[d] = mas[c];
		   count = count+2;
		   continue;
		}
		if(count > value)
		   break;
		count++;
		already++;
	}
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

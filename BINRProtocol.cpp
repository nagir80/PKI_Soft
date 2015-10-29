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
{   char mas[20] = {0}; // ������ ������������� �������.
	int must = 0; // ���.�������� �����. ����� ���������
	int already = 0; // ��� �������� ���. 0x10.  0x10
	int already_pl = 0; // ��������� �� 0x10
	int already_2pl = 0; // ��������� �� ����. ������� �� 0x10
	int already_3pl = 0; // ��������� �� ����. ������� �� 0x10 0x10
	int value = index_ - 2; // ���.�������� �� ����������� 2-� ����������.
	int count = 2; // ������. 2 - ������ ����� �� ���������� ���������.


	while(1)
	{   if(buf_[count] == 0x10)
		{  already++;
		   already_pl = already + 1;
		   already_2pl = already_pl + 1;
		   already_3pl = already_2pl + 1;
		   must = value - already; // ��������� ���-�� ���������� ��� �������� ��������.
		   for(int a = 0,b = already_2pl; a < must; a++,b++) //  ������������� ������� � mas
			  mas[a] = buf_[b];

		   buf_[already_2pl] = 0x10; // ��������� 0x10 �� 0x10.
		   index_++;
		   already++; // �������� � ���-�� ��� ���� 0x10
		   value++; // ����� ���-�� �������� ����������� �� 1.
		   for(int c = 0,d = already_3pl; c < must; c++,d++) // ������� ������� � buf_
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

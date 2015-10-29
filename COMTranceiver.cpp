//---------------------------------------------------------------------------
#pragma hdrstop

#include "COMTranceiver.h"
#include "Registry.hpp"
#include "utils.h"
//#include "main.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib>
#include <windows.h>


inline void func(char &ch_,char* mas_,char* mas3_, FILE* file_,int &i_)
{   int h;
	for(h = 0; h <= 50; h++)
	   mas_[h] = 0;
	h = 0;
	do
	  {
		  if(mas3_[i_] == ',')
			{   i_++;
				break;
			}
		  mas_[h] = mas3_[i_]; h++;
	  } while(mas3_[i_++] != '.');
}

//------------------------------------------------------------------------------
COM_Settings::COM_Settings(IProtocol* prt, wchar_t* name, BAUD baud, DATA_BITS db, PARITY par, STOP_BITS sb, FLOW_CTR fc):ISettings(prt, SERIAL)
{   this->name = name;
	this->baud = baud;
	this->db = db;
	this->par = par;
	this->sb = sb;
	this->fc = fc;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
char* COM_Settings::print(void)
{   char res[100] = {0};
	sprintf(res, "Port: %S  Baudrates: %d  Data Bits: %d  Parity: %d  Stop Bits %d  Flow Control: %d",this->name, Utils::baudesToInt(baud), Utils::dbToInt(db), Utils::parToInt(par), Utils::sbToInt(sb), Utils::fcToInt(fc));
	return res;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
COM_Tranceiver::COM_Tranceiver(ISettings* i_set, HANDLE &sus):ITranceiver(i_set),suspTr(sus)
{   this->i_set = (COM_Settings*) i_set;
	COMport = CreateFile((const wchar_t*)this->i_set->getName(),GENERIC_READ | GENERIC_WRITE,0,0,OPEN_EXISTING,FILE_FLAG_OVERLAPPED,0);
	 if(COMport == INVALID_HANDLE_VALUE)  // ���� ������ �������� �����.
		addResult(1);
	 dcb.DCBlength = sizeof(DCB);
	 if (!GetCommState(COMport, &dcb)) // ���� �� ��������� ������ � ������� ���������� � __COMPort.
		addResult(2);
	 initDCB();
	 ftimeouts();
	 if (!SetCommState(COMport, &dcb)) // ���� �� ��������� ������ � ������� ���������� � __COMPort.
		addResult(4);
	 mutex_1 = CreateMutex(NULL, FALSE, (const wchar_t*)"fm");
	 ExecuteTr();
	 ExecuteRsv();
};
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
COM_Tranceiver::~COM_Tranceiver()
{   CloseHandle(getOvlWr()->hEvent); // ����� ������� ������-�������
	CloseHandle(getOvlRd()->hEvent); // ����� ������� ������-�������
	CloseHandle(*getCOM());             // ������� ����
	clrCOM();			          // �������� ���������� ��� ����������� �����.
	delete getSettings();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void COM_Tranceiver::addToRdBuf(char* buf, unsigned short size)
{   WaitForSingleObject(mutex_1, 0);
	if(size <= (1023-rd_in))
	   memcpy(bufrd+rd_in, buf, size);
	else
	  {   memcpy(bufrd + rd_in, buf, 1023-rd_in);
		  memcpy(bufrd, buf + (1023-rd_in), size - (1023-rd_in));
	  }
	rd_in = (rd_in + size) & 0x3FF;
	size_rd += size;
	if ((size_rd > 1024))
	   size_rd = -1;
	ReleaseMutex(mutex_1);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void COM_Tranceiver::getFromRdBuf(char *buf, unsigned short size)
{   WaitForSingleObject(mutex_1, 0);
	unsigned short real_size = (size < size_rd)?size:size_rd;
	if(real_size <= (1023-rd_out))
	   memcpy(buf, bufrd+rd_out, real_size);
	else
	  {  memcpy(buf, bufrd+rd_out, 1023-rd_out);
		 memcpy(buf + 1023-rd_out, bufrd, real_size - (1023-rd_out));
	  }
	rd_out = (rd_out + real_size) & 0x3FF;
	if (size_rd != -1) size_rd -= real_size;
	   ReleaseMutex(mutex_1);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
DWORD COM_Tranceiver::rsvThreadFunc()
{   COMSTAT comstat; //��������� �������� ��������� �����, � ������ ��������� ������������ ��� ����������� ���������� �������� � ���� ������
	DWORD btr = 0, temp = 0, mask = 0, signal = 0; //���������� temp ������������ � �������� ��������
	char *hlp_buf = 0;

	overlappedrd.hEvent = CreateEvent(NULL, true, true, NULL); //������� ���������� ������-������� ���
	SetCommMask(COMport, EV_RXCHAR); //���������� ����� �� ������������ �� �������  ����� ����� � ����
	while(1) //���� ����� �� ����� �������, ��������� ����
		 {   WaitCommEvent(COMport, &mask, &overlappedrd); //������� ������� ����� ����� (��� � ���� ������������� ��������)
			 signal = WaitForSingleObject(overlappedrd.hEvent, INFINITE); //������������� ����� �� ������� �����
			 if(signal == WAIT_OBJECT_0) //���� ������� ������� ����� ���������
			   {   if(GetOverlappedResult(COMport, &overlappedrd, &temp, true)) //���������, ������� �� ����������� �������������  �������� WaitCommEvent
					  if((mask & EV_RXCHAR)!=0) //���� ��������� ������ ������� ������� �����
						{   ClearCommError(COMport, &temp, &comstat); //����� ��������� ��������� COMSTAT
							btr = comstat.cbInQue; //� �������� �� �� ���������� �������� ������
							if (btr)
							   {   hlp_buf = new char[btr];
								   ReadFile(COMport, hlp_buf/*bufrd*/, btr, &temp, &overlappedrd); //��������� ����� �� ����� � ����� ���������
								   addToRdBuf(hlp_buf, btr);
								   delete [] hlp_buf;
							   }
						}
			   }
		 }
	return 0;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
DWORD COM_Tranceiver::trThreadFunc()
{   DWORD temp = 0, signal = 0; // temp - ����������-��������
	overlappedwr.hEvent = CreateEvent(NULL, true, true, NULL); //������� �������
	while(1)
		{   WriteFile(COMport, bufwr, size_wr, &temp, &overlappedwr); // �������� ����� � ���� (������������� ��������!)
			signal = WaitForSingleObject(overlappedwr.hEvent, INFINITE); // ������������� �����, ���� �� ���������� ������������� �������� WriteFile
			if(signal == WAIT_OBJECT_0)
			   GetOverlappedResult(COMport, &overlappedwr, &temp, true); // ���� �������� ����������� �������
			size_wr = size_wr - temp;
			SetEvent(suspTr);
			SuspendThread(m_hThread2);
		}
}
//------------------------------------------------------------------------------

//---------------------------��������� com-�����--------------------------------
TStringList* COM_Settings::all_ports(void)
{   TStringList *list = new TStringList;
	TStringList *list2 = new TStringList;

	TRegistry *Reg = new TRegistry();
	AnsiString w,d;
	Reg->RootKey = HKEY_LOCAL_MACHINE;
	Reg->OpenKey("HARDWARE\\DEVICEMAP\\SERIALCOMM", false);
	Reg->GetValueNames(list);
	static int i = 0;
	for (; i < list->Count;)
	   {   w = Reg->ReadString(list->Strings[i]).SetLength(3);
		   if ( w.SetLength(3) == "COM")
			  {   d = Reg->ReadString(list->Strings[i++]);
				  list2->Add(d);
			  }
	   }
	list->Free();
	Reg->CloseKey();
	Reg->Free();
	i = 0;
	return list2;
}
//---------------------------------end------------------------------------------

//--------------������������� ��������� DCB ��� com-�����-----------------------
void COM_Tranceiver::initDCB()
{    dcb.BaudRate = Utils::baudesToInt(getSettings()->getBaud());    // ����� �������� ��������.

	 dcb.fBinary = true;       // �������� �������� ����� ������.
	 dcb.fOutxCtsFlow = false; // ��������� ����� �������� �� �������� CTS.
	 dcb.fOutxDsrFlow = false; // ��������� ����� �������� �� �������� DSR.
	 dcb.fDtrControl = DTR_CONTROL_DISABLE; // ��������� ������������� ����� DTR.
	 dcb.fDsrSensitivity = false; // ��������� ��������������� �������� � ��������� ����� DSR.
	 dcb.fNull = false;           // ��������� ���� ������� ������.
	 dcb.fRtsControl = RTS_CONTROL_DISABLE; // ��������� ������������� ����� RTS.
 //	 dcb.fErrorChar = false;
	 dcb.fAbortOnError = FALSE;  // ��������� ��������� ���� �������� ������/������ ��� ������.
	 dcb.ByteSize = Utils::dbToInt(getSettings()->getDB());    // ����� n ��� � �����.
	 dcb.Parity = Utils::parToInt(getSettings()->getPar())  ;             // ��������� �������� ��������.
	 dcb.StopBits = Utils::sbToInt(getSettings()->getSB())  ;           // ����� ���� ����-���.
}
//-------------------------------end--------------------------------------------

//----------------------��������� ���������-------------------------------------
void COM_Tranceiver::ftimeouts(void)
{   timeouts.ReadIntervalTimeout = 10;         // ������� ����� ����� ���������.
	timeouts.ReadTotalTimeoutMultiplier = 10;  // ����� ������� �������� ������.
	timeouts.ReadTotalTimeoutConstant = 10;    // ��������� ��� ������ �������� �������� ������.
	timeouts.WriteTotalTimeoutMultiplier = 10; // ����� ������� �������� ������.
	timeouts.WriteTotalTimeoutConstant = 10;   // ��������� ��� ������ �������� �������� ������.

	// �������� ��������� ��������� � ����.
	 if(!SetCommTimeouts(COMport, &timeouts)) //���� �� ������� - ������� ���� � ������� ��������� �� ������ � ������ ���������
	   {   CloseHandle(COMport);
		   MessageBox ( NULL, L"�� ������� ���������� ��������", L"comPort", MB_OK );
		   return;
	   }
}
//-----------------------------end----------------------------------------------

//------------------------------------------------------------------------------
bool COM_Settings::write_file(void)
{   if((file = fopen("port_settings.txt","a")) == NULL)
	   return 1;

	fstream clear_file("port_settings.txt", ios::out);
	fprintf(file,"%S,%d,%d,%d,%d,%d.",this->name, Utils::baudesToInt(baud),
	Utils::dbToInt(db), Utils::parToInt(par),
	Utils::sbToInt(sb), Utils::fcToInt(fc));

	fclose(file);
	return 0;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
bool COM_Settings::read_file(wchar_t* COM_port1,int& speed1,
	 int& data_bits1,int& Parity1, int& Stop_bits1,
	 int& flow_Control1, int& com_index1)
{
	if((file = fopen("port_settings.txt","a+")) == NULL)
	  return 1;
	if(getc(file) != EOF)
	  {   char buf[100] = {0};
		  char buf1[100] = {0};
		  char buf2[100] = {0};
		  char buf3[100] = {0};
		  char buf4[100] = {0};
		  AnsiString g = all_ports()->GetText();
		  strcpy(buf,g.c_str());
		  rewind(file);
		  fscanf(file,"%s",buf1);
		  int i = 0,j;
		  for(j = 0; buf1[j]  != ','; j++) // ������ � buf3 �� buf1, �� ��� � �����.
			  buf3[j] = buf1[j];
		  while(buf[i] != '\0')
			   {   for(i,j = 0; buf[i] != '\r'; i++,j++) // ������ � buf2 �� buf, �������� ������.
					   buf2[j] = buf[i];
				   if(!(strcmp(buf2,buf3)))// ��������� ��������� buf2 ����� � ������� � ����� buf1
					  break;
				   else
					 {   com_index1++; i += 2;
						 for(int s = 0; s < 100; s++)
							  buf2[s] = 0;
						 continue;
					 }
			   }

		   int d = 0,b,c;
		   for(;;)
			  {   d++;
				  for(int f = 0; f < 100; f++)
					  buf4[f] = 0;
				  for(c = 0; buf1[b] != ',' && buf1[b] != '\0' && buf1[b] != '.'; b++,c++)
					  buf4[c] = buf1[b];
				  if(d == 1) {   b++; continue;   }
				  if(d == 2) speed1 = Utils::indexToBaudes1(atoi(buf4));
				  if(d == 3) data_bits1 = Utils::indexToDb1(atoi(buf4));
				  if(d == 4) Parity1 = Utils::indexToPar(atoi(buf4));
				  if(d == 5) Stop_bits1 = Utils::indexToSb(atoi(buf4));
				  if(d == 6) flow_Control1 = Utils::indexToFc(atoi(buf4));
				  if(d == 7) break;
				  b++;
			  }
	  }
	else
	  {   com_index1 = 0; speed1 = 3; data_bits1 = 0; Parity1 = 3; Stop_bits1 = 0;
		  flow_Control1 = 0;
	  }

	 fclose(file);
	 return 0;
}
//------------------------------------------------------------------------------
int COM_Settings::initialization_file(String* com_ports_,int index)
{   FILE* f;
	if((f = fopen("stend.ini","a+")) == NULL)
	   return 0;

	// ��������..���� ���� ������ ���������� ������ �� ���������, ���� ��� ������� ��������
	// COM-����� � ������� ������������ � stend.ini
	if(getc(f) != EOF)
	{   rewind(f);
		char com_modulator[5] = {0};
		char com_receiver[5] = {0};
		rewind(f);
		fseek(f,46,SEEK_SET);
		fscanf(f,"\n%s",com_modulator);
		fseek(f,144,SEEK_CUR);
		fscanf(f,"\n%s",com_receiver);
		int size = 1;
		bool key = false;
		for(int i = 0; i < index; i++)
		{   AnsiString ss = com_ports_[i];
			if(!strcmp(com_modulator,ss.c_str()))
			{   key = true;
				size = 2;
			}
		}
		for(int j = 0; j < index; j++)
		{   AnsiString dd = com_ports_[j];
			if(!strcmp(com_receiver,dd.c_str()))
			{   if(key)
				   size = 3;
				else
				{   size = 4;
					break;
				}
			}
		}
		if(!strcmp(com_modulator,com_receiver))
		   size = 6;
		fclose(f);
		return size;
	}
	else
	{   fclose(f);
		if((f = fopen("stend.ini","a")) == NULL)
		  return 0;

		fstream clear_file("stend.ini", ios::out);
		fprintf (f, "%s%S%s%d%s%d%s%d%s%d%s%d",
		";==========���������==========\n\n;COM-����:\n",
		this->name,"\n;��������:\n", Utils::baudesToInt(baud),"\n;���� ������:\n",
		Utils::dbToInt(db),"\n;׸������:\n", Utils::indexToPar(par),"\n;�������� ����:\n",
		Utils::sbToInt(sb),"\n;���������� �������\n", Utils::fcToInt(fc));
		this->name = com_ports_[1].w_str();
		fprintf (f, "%s%S%s%d%s%d%s%d%s%d%s%d",
		"\n\n;==========�������==========\n\n;COM-����:\n", this->name,"\n;��������:\n",
		Utils::baudesToInt(baud),"\n;���� ������:\n",Utils::dbToInt(db),"\n;׸������:\n",
		Utils::indexToPar(par),"\n;�������� ����:\n",Utils::sbToInt(sb),"\n;���������� �������\n",
		Utils::fcToInt(fc));
	 }
	fclose(f);
	return 5;
}
//------------------------------------------------------------------------------

#pragma package(smart_init)

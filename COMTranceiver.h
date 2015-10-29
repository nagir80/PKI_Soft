//---------------------------------------------------------------------------

#ifndef COMTranceiverH
#define COMTranceiverH

#include "ITranceiver.h"
#include "Registry.hpp"
#include <string>





enum BAUD { BR_600 = 600, BR_1200 = 1200, BR_2400 = 2400, BR_4800 = 4800, BR_9600 = 9600, BR_14400 = 14400, BR_19200 = 19200, BR_38400 = 38400, BR_57600 = 57600, BR_115200 = 115200 };
enum DATA_BITS { DB_5 = 5, DB_6 = 6, DB_7 = 7, DB_8 = 8, DB_9 = 9};
enum PARITY  { PAR_NONE = 0, PAR_ODD = 1, PAR_EVEN = 2};
enum STOP_BITS { SB_ONE = 0, SB_ONE_HALF = 1, SB_TWO = 2};
enum FLOW_CTR {FC_NONE = 0, FC_XON = 2, FC_CTS = 1};


class COM_Settings : public ISettings{
private:
	wchar_t* name;
	BAUD baud;
	DATA_BITS db;
	PARITY par;
	STOP_BITS sb;
	FLOW_CTR fc;
	char array[20];
	FILE *file;
	int com_index;

public:
	char* print(void);
	static TStringList* all_ports(void);      // Отображение имеющихся портов.
	bool open_port(String, int, int);
	bool write_file(void); // Запись в файл конфиг. порта.
	bool read_file(wchar_t*,int&,int&,int&,int&,int&,int&); // Чтение из файла кон. порта.

	wchar_t* getName(){ return name; }
	BAUD getBaud(){ return baud; }
	DATA_BITS getDB(){ return db; }
	PARITY getPar(){ return par; }
	STOP_BITS getSB(){ return sb; }
	FLOW_CTR getFC(){ return fc; }
    int initialization_file(String*,int);

	COM_Settings(IProtocol* prt, wchar_t* name, BAUD baud, DATA_BITS db, PARITY par, STOP_BITS sb, FLOW_CTR fc);
};



class COM_Tranceiver : public ITranceiver{

	HANDLE mutex_1;
	HANDLE COMport;              // Дескриптор com-порта.
	OVERLAPPED overlappedwr;     // Для операций записи.
	OVERLAPPED overlappedrd;     // Для операций чтения.
	DCB dcb;                     // Структура для общей инициализации порта DCB.
	COMMTIMEOUTS timeouts;       // Структура для установки таймаутов.
	void addToRdBuf(char* buf, unsigned short size);
protected:
	COM_Settings* i_set;

public:

	friend void Test_addToRdBuf(COM_Tranceiver* i, char* buf, unsigned short size);
COM_Tranceiver::COM_Tranceiver(ISettings* i_set, HANDLE &sus);
	~COM_Tranceiver();
	COM_Settings* getSettings() { return i_set; }
	void getFromRdBuf(char *buf, unsigned short size);
    short getSizeRd(void){return size_rd;}
  	HANDLE &suspTr;

	void initDCB();         // Инициализация структуры DCB для com-порта.
	void ftimeouts(void);        // Таймауты.

	DWORD WINAPI ReadThread(LPVOID);

	HANDLE* getCOM(){return &COMport;}
	void clrCOM(){COMport=0;}
	OVERLAPPED* getOvlWr(){return &overlappedwr;}
	OVERLAPPED* getOvlRd(){return &overlappedrd;}

	DCB* getDCB() {return &dcb;}
	COMMTIMEOUTS* getCTO(){return &timeouts;}
	void setSizeWr(short wr){ size_wr = wr;}
	short getSizeWr(void){ return size_wr;}
protected:
	DWORD rsvThreadFunc();
	DWORD trThreadFunc();


};

void Test_addToRdBuf(COM_Tranceiver* i, char* buf, unsigned short size){
   	 i->addToRdBuf(buf,size);
}

//---------------------------------------------------------------------------
#endif

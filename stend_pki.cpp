//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("StendPKI\main_sp.cpp", Form1);
USEFORM("StendPKI\nine.cpp", Form3);
USEFORM("StendPKI\seven.cpp", Form2);
USEFORM("StendPKI\sixteen.cpp", Form4);
USEFORM("StendPKI\thirty_five.cpp", Form6);
USEFORM("StendPKI\thirty_four.cpp", Form5);
USEFORM("StendPKI\thirty_six.cpp", Form7);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TForm4), &Form4);
		Application->CreateForm(__classid(TForm6), &Form6);
		Application->CreateForm(__classid(TForm5), &Form5);
		Application->CreateForm(__classid(TForm7), &Form7);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------

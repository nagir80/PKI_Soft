//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main_sp.h"
#include "seven.h"
#include "nine.h"
#include "sixteen.h"
#include "thirty_four.h"
#include "thirty_five.h"
#include "thirty_six.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{}
//---------------------------------------------------------------------------


void __fastcall TForm4::Button2Click(TObject *Sender)
{   Form4->Close();
}
//---------------------------------------------------------------------------




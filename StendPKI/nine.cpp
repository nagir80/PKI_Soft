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
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{   Form3->Close();
}
//---------------------------------------------------------------------------



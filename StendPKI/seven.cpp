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
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{   Form2->Close();
}
//---------------------------------------------------------------------------





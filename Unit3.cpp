//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//invertir numero
void invertir_numero(Cardinal &x){
if(x>10){
   byte d=x%10;
   x=x/10;
   invertir_numero(x);
  byte Cant_Dig=(log10((double)x)+1);
  x=d*pow(10,Cant_Dig)+x;
}

}
void __fastcall TForm3::Button1Click(TObject *Sender)
{
   Cardinal x=Edit1->Text.ToInt();
   invertir_numero(x);
   Edit1->Text=x;
}
//---------------------------------------------------------------------------
byte sumar_digitos(Cardinal x){
byte s; 
if(x==0){
    s=0;
 }else{
    byte d=x%10;
	s=sumar_digitos(x/10);
	s=s+d;
 }	
}	

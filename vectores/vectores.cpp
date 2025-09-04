//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "vectores.h"
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
void __fastcall TForm3::Button1Click(TObject *Sender)
{
  byte cantidad=Edit1->Text.ToInt();
  StringGrid1->ColCount=cantidad;
}
//---------------------------------------------------------------------------
//SUMAR ELEMENTOS DEL VECTOR
byte suma_elementos_vector(TStringGrid *v,byte n){
  byte s;
  if(n==0){
	 s=0;
  }else if(n==1){
	 s=v->Cells[0][0].ToInt();
  }else{
	  byte d =v->Cells[n-1][0].ToInt();
	  s=suma_elementos_vector(v,n-1);
      s=s+d;
  }
  return s;
}

void __fastcall TForm3::SumaElementosV1Click(TObject *Sender)
{

   Edit3->Text=suma_elementos_vector(StringGrid1,Edit1->Text.ToInt());
}
//---------------------------------------------------------------------------
//dado un vector [9,27,3,12]-> x=123279
Cardinal vector_cadena_inverso(TStringGrid *v,byte n){
 Cardinal x;
 if(n==0){
   x=0;
 }else if(n==1){
	x=v->Cells[0][0].ToInt();
 }else{
	 Word valor=v->Cells[n-1][0].ToInt();
	 x=vector_cadena_inverso(v,n-1);
	 byte cant_dig=log10((double)x)+1;
	 x=valor*pow(10,cant_dig)+x;
 }
 return x;
}

void __fastcall TForm3::VectorAcadenaInversa1Click(TObject *Sender)
{
   Edit3->Text=vector_cadena_inverso(StringGrid1,Edit1->Text.ToInt());
}
//---------------------------------------------------------------------------


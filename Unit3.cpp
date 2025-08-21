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
if(x<10){
	s=x;
 }else{
    byte d=x%10;
	s=sumar_digitos(x/10);
	s=s+d;
 }
 return s;
}
void __fastcall TForm3::Button2Click(TObject *Sender)
{
	 Edit2->Text=sumar_digitos(Edit1->Text.ToInt());
}
//---------------------------------------------------------------------------
//funcion que devuelva el mayor de los digitos de un numero
byte mayor_digito(Cardinal x){
 byte m;
  if(x<10){
	m=x;
  }else{
	 byte d=x%10;
	 m=mayor_digito(x/10);
	 if(d>m)
	   m=d;
  }
  return m;
}

void __fastcall TForm3::Button3Click(TObject *Sender)
{
   Edit2->Text=mayor_digito(Edit1->Text.ToInt());
}
//---------------------------------------------------------------------------
//algoritmo para eliminar el digito z de un numero
//eje x=42872981 , z=2 -> x=487981
void eliminarZ(Cardinal &x,byte z){
  if(x<10){
	 if(x==z)
		x=0;
  }else{
	 byte d=x%10;
	 x=x/10;
	 eliminarZ(x,z);
	 if(d!=z)
		x=x*10+d;
  }
}
void __fastcall TForm3::Button4Click(TObject *Sender)
{
   Cardinal x=Edit1->Text.ToInt();
   byte z=Edit2->Text.ToInt();
   eliminarZ(x,z);
   Edit1->Text=x;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Cadenas.h"
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
//contar vocales que hay en una cadena
bool EsVocal(char z){
   AnsiString vocales="aeiouAEIOU";
   return vocales.Pos(z)>0;
}
//x=hola a todos ->c=5
//PID V1
byte CantVocales(AnsiString x){
  byte c;
  if(x==""){
	  c=0;
  }else{
	  char z=x[1];
	  x.Delete(1,1);
	  c=CantVocales(x);
	  if(EsVocal(z))
         c++;
  }
  return c;
}
void __fastcall TForm3::Button1Click(TObject *Sender)
{
   Edit2->Text=CantVocales(Edit1->Text);
}
//---------------------------------------------------------------------------
//invertir cadena
//x=hola mundo -> odnum aloh = primer principio
void invertir_cadena(AnsiString &x){
 byte longitud=x.Length();
   if(longitud>1){
	  //char z=x[1];
	  AnsiString y=x.SubString(1,2);
	  //x.Delete(1,1);
	  x.Delete(1,2);
	  invertir_cadena(x);
	  //x=x+z;
	  x=x+y[2]+y[1];
   }
}
AnsiString invertir_cadena1(AnsiString x){
 AnsiString y;
 byte longitud=x.Length();
 if(x==""){
	y="";
 }else{
	 char z=x[1];
	 x.Delete(1,1);
	 y=invertir_cadena1(x);
	 y=y+z;
 }
 return y;
}
// usando segundo principio  PID
void invertir_cadena2(AnsiString &x){
   byte longitud=x.Length();
   if(longitud>1){
	  char z=x[1];
	  char y=x[2];
	  x.Delete(2,1);
	  x.Delete(1,1);
	  invertir_cadena2(x);
	  x=x+y+z;
   }
}
 //usando 2 PID
void invertir_cadena2_1(AnsiString &x){
 byte longitud=x.Length();
 if(longitud>1){
	AnsiString y=x.SubString(1,longitud/2);
	x.Delete(1,longitud/2);
	invertir_cadena2_1(x);
	invertir_cadena2_1(y);
	x=x+y;
 }
}
AnsiString invertir_cadena2_11(AnsiString x){
 AnsiString y;  byte longitud=x.Length();
 if(longitud==0){
   y="";
 }else if(longitud==1){
	   y=x;
 }else{
	 AnsiString z=x.SubString(longitud/2+1,longitud-longitud/2);
	 x.Delete(longitud/2+1,longitud-longitud/2);
	 y=invertir_cadena2_11(z)+invertir_cadena2_11(x);
 }
 return y;
}

void __fastcall TForm3::Button2Click(TObject *Sender)
{
  /* AnsiString x=Edit1->Text;
   invertir_cadena(x);
   Edit1->Text=x; */
   Edit2->Text=invertir_cadena2_11(Edit1->Text);

}
//---------------------------------------------------------------------------

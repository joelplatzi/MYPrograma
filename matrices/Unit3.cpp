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
 /*
 1   2  3  4  5
 6   7  8  9 10
 11 12 13 14 15
 16 17 18 19 20

 */
void cargar_columnas(TStringGrid *m,byte ca,byte cb,byte &v){
 byte c=ca-cb+1;
 if(c<=m->ColCount){
	 m->Cells[ca][cb]=v;
	v++;
	cargar_columnas(m,ca+1,cb,v);
	//m->Cells[ca][cb]=v;
	//v++;

 }
}
void cargar_filas(TStringGrid *m,byte fa,byte fb,byte &v){
 byte f=fb-fa+1;
  if(f>0){
	 cargar_filas(m,fa,fb-1,v);
	 cargar_columnas(m,fa,fb,v);
  }
}
void CargarColumna(TStringGrid *M,byte f,byte c,byte &v){
 if(c!=M->ColCount){
	v++;
	M->Cells[c][f]=v;
	CargarColumna(M,f,c+1,v);
 }else{
	 return;
 }
}
void CargarFila(TStringGrid *M,byte f,byte &v){
 if(f!=M->RowCount){
	CargarColumna(M,f,0,v);
	CargarFila(M,f+1,v);
 }else{
	 return;
 }
}
void CargarColumna2(TStringGrid *M,byte f,byte c,byte &v){
 if(c>0){
	 v++;
	 M->Cells[c-1][f-1]=v;
	 CargarColumna2(M,f,c-1,v);
 }
}
void CargarFila2(TStringGrid *M,byte f,byte &v){
  if(f>0){
	  CargarColumna2(M,f,M->ColCount,v);
	  CargarFila2(M,f-1,v);
  }else{
	  return;
  }
}
/*
  3 2 1
  6 5 4
  9 8 7
*/
void CargarColumna3(TStringGrid *M,byte f,byte c ,byte &v){
 if(c>0){
	v++;
	M->Cells[c-1][f]=v;
	CargarColumna3(M,f,c-1,v);
 }
}
void CargarFila3(TStringGrid *M , byte f,byte &v){
if(f==M->RowCount){
	return;
}else{
	CargarColumna3(M,f,M->ColCount,v);
	CargarFila3(M,f+1,v);
}

}
void __fastcall TForm3::cargarmatriz1Click(TObject *Sender)
{
   StringGrid1->RowCount=Edit1->Text.ToInt();
   StringGrid1->ColCount=Edit2->Text.ToInt();
   byte n=0;
   //CargarFila(StringGrid1,0,n);
   //CargarFila2(StringGrid1,StringGrid1->RowCount,n);
   CargarFila3(StringGrid1,0,n);
   /*byte v=1;
   StringGrid1->RowCount=Edit1->Text.ToInt();
	StringGrid1->ColCount=Edit2->Text.ToInt();
   cargar_filas(StringGrid1,0,StringGrid1->RowCount,v);   */
}
//---------------------------------------------------------------------------
/*
  1 6 7
  2 5 8
  3 4 9
*/
void cargarFilaNivel2_1(TStringGrid *M,byte f,byte c,byte &v){
 if(f>0){
   v++;
   M->Cells[c][f-1]=v;
   cargarFilaNivel2_1(M,f-1,c,v);
 }
}
void cargarFilaNivel2(TStringGrid *M,byte f,byte c,byte &v){
 if(f==M->RowCount){
   return;
 }else{
	v++;
	M->Cells[c][f]=v;
	cargarFilaNivel2(M,f+1,c,v);
 }
}
void cargarColumnaNivel2(TStringGrid *M,byte c,bool b,byte &v){
  if(c==M->ColCount){
	 return;
  }else{
	  if(b==true){
		 b=false;
		 cargarFilaNivel2(M,0,c,v);
	  }else{
		  b=true;
		  cargarFilaNivel2_1(M,M->RowCount,c,v);
	  }
	  cargarColumnaNivel2(M,c+1,b,v);
  }
}


void __fastcall TForm3::cargarNivel21Click(TObject *Sender)
{
 bool b=true;
 byte v=0;
  StringGrid1->RowCount= Edit1->Text.ToInt();
  StringGrid1->ColCount= Edit2->Text.ToInt();
 cargarColumnaNivel2(StringGrid1,0,b,v);
}
//---------------------------------------------------------------------------
//pregunta del examen m=5 p=4  matriz cuadrada
/*
   20 11 10 0 1
   19 12  9 0 2
   18 13  8 0 3   p=posicion a dejar en vacio o cero
   17 14  7 0 4
   16 15  6 0 5
*/
void pregunta1_F_1(TStringGrid *M,byte f,byte c,byte &v){
  if(f>0){
	v++;
	M->Cells[c-1][f-1]=v;
	pregunta1_F_1(M,f-1,c,v);
  }
}
void pregunta1_F(TStringGrid *M,byte f,byte c,byte &v){
  if(f==M->RowCount){
	 return;
  }else{
	  v++;
	  M->Cells[c-1][f]=v;
	  pregunta1_F(M,f+1,c,v);
  }
}
void pregunta1(TStringGrid *M,byte c,bool b,byte &v,byte p){
 if(c>0){
	if(p==c){
	   pregunta1(M,c-1,b,v,p);
	}
	if(b==true){
	   b=false;
	   pregunta1_F(M,0,c,v);
	}else{
		b=true;
		pregunta1_F_1(M,M->RowCount,c,v);
	}
	pregunta1(M,c-1,b,v,p);
 }
}
void __fastcall TForm3::pregunta11Click(TObject *Sender)
{
   byte p=Edit3->Text.ToInt();
   bool b=true;
  byte v=0;
  StringGrid1->RowCount= Edit1->Text.ToInt();
  StringGrid1->ColCount= Edit2->Text.ToInt();
  pregunta1(StringGrid1,StringGrid1->ColCount,b,v,p);
}
//---------------------------------------------------------------------------


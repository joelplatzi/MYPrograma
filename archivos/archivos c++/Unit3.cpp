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
bool EsVocal(char x){
   AnsiString vocales="aeiouáéíóúAEIOUÁÉÍÓÚ";
   return vocales.Pos(x)>0;
}
Cardinal CantVoc(AnsiString nom){
  char x; Cardinal c=0;
  fstream pf(nom.c_str());
  if(!pf.fail()){  //si no fallo al abrir
	  while(!pf.eof()){ //mientras no hayga leido la marca de fin de archivo
		  x=pf.get();
		  if(!pf.eof()){
			  if(EsVocal(x)){
				 c++;
			  }
		  }
	  }
	  pf.close();
  }
  return c;
}
void __fastcall TForm3::Button2Click(TObject *Sender)
{
   if(OpenTextFileDialog1->Execute()){
	  Edit1->Text=OpenTextFileDialog1->FileName;
	  Edit2->Text=CantVoc(OpenTextFileDialog1->FileName);
   }
}
//---------------------------------------------------------------------------
Cardinal CantDig(AnsiString nom){
  Cardinal c=0; char x;
  fstream pf(nom.c_str());
  if(!pf.fail()){ //sino fallo al abrir
	 while(!pf.eof()){
		x=pf.get();
		if(!pf.eof()){
		   if(isdigit(x)){
			  c++;
		   }
		}
	 }
	 pf.close();
  }
  return c;
}
void __fastcall TForm3::Button3Click(TObject *Sender)
{
  //para saber la ubicacion del archivo
  if(OpenTextFileDialog1->Execute()){
	  Edit1->Text=OpenTextFileDialog1->FileName;
	  Edit2->Text=CantDig(OpenTextFileDialog1->FileName);
  }
}
//---------------------------------------------------------------------------
Cardinal CantNumeros(AnsiString num){
 byte c=0; char x; bool b;
 fstream pf(num.c_str());
 if(!pf.fail()){
	 b=false;
	 while(!pf.eof()){
		 x=pf.get();
		 if(!pf.eof()){
			if(isdigit(x)){
			   if(!b){
				  c++;
				  b=true;
			   }
			}else{
				b=false;
            }
		 }
	 }
     pf.close();
 }
 return c;
}
void __fastcall TForm3::Button4Click(TObject *Sender)
{
   if(OpenTextFileDialog1->Execute()){
	   Edit1->Text=OpenTextFileDialog1->FileName;
	   Edit2->Text=CantNumeros(OpenTextFileDialog1->FileName);
   }
}
//---------------------------------------------------------------------------
bool EsPalabra(char x){
  AnsiString pal="qwertyuiopasdfghjklñzxcvbnmQWERTYUIOPASDFGHJKLÑZXCVBNM";
  return pal.Pos(x)>0;
}
Cardinal CantPalabras(AnsiString pal){
  Cardinal c=0; char x; bool b;
  fstream pf(pal.c_str());
  if(!pf.fail()){
	 b=false;
	 while(!pf.eof()){
		x=pf.get();
		if(!pf.eof()){
		   if( EsPalabra(x)){
			  if(!b){
				 c++;
				 b=true;
			  }
		   }
		   else{
			   b=false;
           }
		}
	 }
	 pf.close();
  }
  return c;
}
void __fastcall TForm3::Button5Click(TObject *Sender)
{
  if(OpenTextFileDialog1->Execute()){
	 Edit1->Text=OpenTextFileDialog1->FileName;
	 Edit2->Text=CantPalabras(OpenTextFileDialog1->FileName);
  }
}
//---------------------------------------------------------------------------
void CantPal_linea(AnsiString pal){
 Cardinal c=0; char x; bool b; AnsiString linea;
 fstream pf(pal.c_str());
 ofstream pf2("D:\\POO\\inf210\\archivos_textos\\salida.txt");
 if(!pf.fail()){
	 b=false;
	 while(!pf.eof()){
		x=pf.get();
		if(!pf.eof()){
			if(EsPalabra(x)){
				if(!b){
					c++;
					b=true;
				}
			}else if(x==10){  //fin de linea
			   //	ShowMessage(c);
			   linea=c;
			   for (Word i=1;i<=linea.Length(); i++ ){
				  pf2.put(linea[i]);
			   }
			   //	pf2.put(c+48);
				pf2.put(10);
				c=0;
				b=false;
			}else{
				b=false;
			}
		}
	 }
	 linea=c;
      for (Word i=1;i<=linea.Length(); i++ ){
		   pf2.put(linea[i]);
	  }
	 //pf2.put(c+48);
	 pf.close();
	 pf2.close();
 }
 // return c;
}


void __fastcall TForm3::Button6Click(TObject *Sender)
{
  if(OpenTextFileDialog1->Execute()){
	  Edit1->Text=OpenTextFileDialog1->FileName;
	  CantPal_linea(OpenTextFileDialog1->FileName);
  }
}
//---------------------------------------------------------------------------
void CantNum_linea(AnsiString num){
 byte c=0; char x; bool b;  AnsiString linea;
 fstream pf(num.c_str());
 ofstream pf2("salida2.txt");
 if(!pf.fail()){
   b=false;
   while(!pf.eof()){
	   x=pf.get();
	   if(!pf.eof()){
		   if(isdigit(x)){
			   if(!b){
				  c++;
				  b=true;
			   }
		   }else if(x==10){
			   //ShowMessage(c);
			   linea=c;
			   for(Word i=1; i<=linea.Length(); i++){
				   pf2.put(linea[i]);
			   }
			  // pf2.put(c+48);
			   pf2.put(10);
			   c=0;
			   b=false;
		   }else{
			   b=false;
           }
	   }
   }
   //pf2.put(c+48);
   linea=c;
   for(Word i=1; i<=linea.Length(); i++){
       pf2.put(linea[i]);
   }
   pf.close();
   pf2.close();
 }

 //return c;

}


void __fastcall TForm3::Button7Click(TObject *Sender)
{
  if(OpenTextFileDialog1->Execute()){
	  Edit1->Text=OpenTextFileDialog1->FileName;
	  CantNum_linea(OpenTextFileDialog1->FileName);
	 // Edit2->Text=CantNum_linea(OpenTextFileDialog1->FileName);
  }
}
//---------------------------------------------------------------------------
void Primer_Palabra(AnsiString nom){
 AnsiString pal; char x; bool b;   char x1;
 fstream pf(nom.c_str());
 ofstream pf2("salida.txt");
 if(!pf.fail()){
	 while(!pf.eof()){
		 x=pf.get();
		 b=true;
		 pal="";
		while(!pf.eof() && x!=10){
		   if(EsPalabra(x) && b){
			  if(pal=="") x=UpCase(x);
			  pal=pal+x;
		   }else if(pal!="" && b){
			   b=false;
			   pal=pal+", " ;
		   }
		   x=pf.get();
		}

		for(Word i=1; i<=pal.Length(); i++){
			pf2.put(pal[i]);
		}
		//ShowMessage(pal);

	  /*	if(pal!=""){
		   pf2 << (pal+", ");
		}  */
	 }
	 pf2.close();
	 pf.close();
 }
 //return pal;

}

void __fastcall TForm3::Button8Click(TObject *Sender)
{
  if(OpenTextFileDialog1->Execute()){
	  Edit1->Text=OpenTextFileDialog1->FileName;
	  Primer_Palabra(OpenTextFileDialog1->FileName);
	 // Edit2->Text=Primer_Palabra(OpenTextFileDialog1->FileName);
  }
}
//---------------------------------------------------------------------------
void get_primer_numero(AnsiString nom){
 Cardinal c=0; char x; bool sw;   AnsiString num;
 fstream pf(nom.c_str());
 ofstream pf2("salida2.txt");
 if(!pf.fail()){
	 while(!pf.eof()){
		 sw=true;
		 x=pf.get();
		 num="";
		 while(!pf.eof() && x!=10){
			if(isdigit(x) && sw){
			   num=num+x;
			}else if(num!="" && sw){
				sw=false;
				num=num+", ";
			}
			x=pf.get();
		 }

		 for(Word i=1; i<=num.Length(); i++){
			 pf2.put(num[i]);
		 }
		// pf2.put(10);
		 //ShowMessage(num);
	 }
	 pf2.close();
	 pf.close();
 }

 //return c;
}


//---------------------------------------------------------------------------
AnsiString get_ultima_palabra(AnsiString nom){
 AnsiString pal; char x; bool sw;
 fstream pf(nom.c_str());
 ofstream pf2("salida3.txt");
 if(!pf.fail()){

	 while(!pf.eof()){
		 // pal="";
		  x=pf.get(); //75holo_mundo27
		  while(!pf.eof() && x!=10){   //fin de linea
			 if(EsPalabra(x) ){
				pal="";
				 while(EsPalabra(x)){
					pal=pal+x;
					x=pf.get();
				 }
				// pal=pal+x;
			 }else
			   x=pf.get();
		  }
		 // ShowMessage(pal);
		 pal=pal+", ";
		 for(Word i=1; i<=pal.Length(); i++){
              pf2.put(pal[i]);
		 }
	 }
	 pf.close();
	 pf2.close();
 }
 return pal;
}
void __fastcall TForm3::Button9Click(TObject *Sender)
{
  if(OpenTextFileDialog1->Execute()){
	 Edit1->Text=OpenTextFileDialog1->FileName;
	 //get_primer_numero(OpenTextFileDialog1->FileName);
	 Edit2->Text=get_ultima_palabra(OpenTextFileDialog1->FileName);
  }
}
//convierte las primeras letras a mayusculas
void MayusMinus(char lin[]){
  Word i,n,p;   bool sw=false;
  AnsiString may="QWERTYUIOPASDFGHJKLÑZXCVBNMÁÉÍÓÚ";
  AnsiString min="qwertyuiopasdfghjklñzxcvbnmáéíóú";
  n=strlen(lin); //para saber la longitud
  for(i=0; i<n; i++){
	 if(EsPalabra(lin[i])){
		if(sw){ //otras letras
		   p=may.Pos(lin[i]);
		   if(p>0){
			   lin[i]=min[p];
		   }
		}else{ //primer letra
			p=min.Pos(lin[i]);
			if(p>0){
			   lin[i]=may[p];
			}
			sw=true;
		}
	 }
  }
}

//como hacer un proceso que me cuente las palabras sean mayusculas
//minusculas mezcladas pero que sea esa palabra mandada por el usuario en c++
/*Modifica el contenido de un archivo de texto de forma que la primer
letra de cada linea este en mausculas y el resto en minusculas
*/
void ActualizarMayMin(AnsiString nom){
 AnsiString linea;  char lin[501]; Word i,n;
 fstream pf(nom.c_str());
 ofstream pf2("temporal.tmp");
 if(!pf.fail()){
	while(!pf.eof()){
	   pf.getline(lin,500);
	  // if(!pf.eof()){
		   MayusMinus(lin);
		   n=strlen(lin);
		   for(i=0; i<n; i++){
			  pf2.put(lin[i]);
		   }
		   if(!pf.eof())
		     pf2.put(10);  //eol =fin de linea
	   //}
	}
   pf.close();
   pf2.close();
   remove(nom.c_str());
   rename("temporal.tmp",nom.c_str());
 }
}
void __fastcall TForm3::Button10Click(TObject *Sender)
{
   if(OpenTextFileDialog1->Execute()){
	  Edit1->Text=OpenTextFileDialog1->FileName;
	  ActualizarMayMin(OpenTextFileDialog1->FileName);
   }
}
//---------------------------------------------------------------------------
/*
Modifica un archivo de forma que cada linea este justificada ala izq
  -   aqui hay          -aqui hay
  -otra pueba           -otra prueba
  -  con             -> -con
  -     texto           -texto
*/
void actualizar_linea1(AnsiString nom){
  AnsiString linea; char lin[501]; Word i,n,p;
  fstream pf(nom.c_str());
  ofstream pf2("temporal.tmp");
  if(!pf.fail()){
	 while(!pf.eof()){
		  pf.getline(lin,500);
		  linea=lin;
		  linea=linea.TrimLeft(); //elimina espacios de la izquierda
		  strcpy(lin,linea.c_str()); //metodo copi
		  //MayusMinus(lin);
		  n=strlen(lin);
		  for(i=0; i<n; i++){
			  pf2.put(lin[i]);
		  }
		  if(!pf.eof()){
			 pf2.put(10);
		  }
	 }
	 pf.close();
	 pf2.close();
	 remove(nom.c_str());//elimina el archivo de entrada
     rename("temporal.tmp",nom.c_str());
  }
}

void __fastcall TForm3::Button11Click(TObject *Sender)
{
   if(OpenTextFileDialog1->Execute()){
	   Edit1->Text=OpenTextFileDialog1->FileName;
       actualizar_linea1(OpenTextFileDialog1->FileName);
   }
}
//---------------------------------------------------------------------------
//algoritmo para encontrar una palabra
void SearchAndReplace(AnsiString name,AnsiString search,AnsiString replace){
 char x;
 byte i; byte n=search.Length();
 AnsiString s;
 AnsiString nameTmp="temporal.tmp";
 ifstream fi(name.c_str());
 ofstream fo(nameTmp.c_str());
 if(!fi.eof()){
   while(!fi.eof()){
	  x=fi.get();
	  if(x==search[1]){
		 s="";
		 i=1;
		 while(i<=n && !fi.eof() && x==search[i]){
			 s=s+x;
			 x=fi.get();
			 i++;
		 }
		 if(i>n){ //se encontro es identico
			fo<< (replace+x);
		 }else{ //no se encontro
			 fo<< (s+x);
         }
	  }else{
		  if(!fi.eof())
			fo.put(x);
      }
   }
   fi.close();
   fo.close();
   remove(name.c_str());
   rename(nameTmp.c_str(),name.c_str());
 }
}

void practico1(AnsiString name,AnsiString search,AnsiString replace){
 AnsiString s; byte i; byte n=search.Length();
 char x;
 AnsiString nameTmp="temporal.tmp";
 fstream f(name.c_str());
 ofstream fo(nameTmp.c_str());
 if(!f.fail()){
   while(!f.eof()){
	  x=f.get();
	  if(x==search[1]){
		 s="";
		 i=1;
		  while(i<=n && !f.eof() && x==search[i]){
			 s=s+x;
			 x=f.get();
			 i++;
		  }
		  if(i>n){ //lo encontro
			 for(Word j=1; j<=replace.Length(); j++){
				 fo.put(replace[j]);
			 }
			 if(!f.eof())
				fo.put(x);
		  }else{ //no lo encontro
			  for(Word j=1; j<=s.Length(); j++){
				  fo.put(s[j]);
			  }
			  if(!f.eof())
				 fo.put(x);
		  }
	  }else{
		  fo.put(x);
      }
   }
   f.close();
   fo.close();
 }
}
Cardinal SearchAndReplace_Cont(AnsiString nom,AnsiString search){
 Cardinal c=0; char x;  byte i;
 Word n=search.Length();
 fstream f(nom.c_str());
 //ofstream fo(search.c_str());
 if(!f.fail()){
	while(!f.eof()){
		 x=f.get();
		 if(x==search[1]){
			i=1;
			while(i<=n && !f.eof() && x==search[i]){
			   x=f.get();
			   i++;
			}
			if(i>n){ //lo encontro
			   c++;
			}
		 }
	}

	f.close();
   //	fo.close();
 }
 return c;
}

void __fastcall TForm3::Button12Click(TObject *Sender)
{
  AnsiString search=Edit1->Text;
  AnsiString replace=Edit2->Text;
  if(OpenTextFileDialog1->Execute()){
	  //SearchAndReplace(OpenTextFileDialog1->FileName,search,replace);
	   //practico1(OpenTextFileDialog1->FileName,search,replace);
	   Edit3->Text=SearchAndReplace_Cont(OpenTextFileDialog1->FileName,search);
  }
}
//---------------------------------------------------------------------------
//Escribir un proceso para generar un archivo de texto que contenga la cantidad de
//palabras y numeros que hay en cada linea de otro archivo de texto
void CantPalAndNum(AnsiString name){
  char x;   byte i,n,p,pal,num;  bool sw,b;
  AnsiString nomArch="lista.txt";
  fstream f(name.c_str());
  ofstream fo(nomArch.c_str());
  if(!f.fail()){
	 sw=false; b=false;
	 pal=0; num=0;
	 while(!f.eof()){
		 x=f.get();
		 if(!f.eof() && x!=10){
			 if(EsPalabra(x)){
				 if(!sw){
					 pal++;
					 sw=true;
				 }
			 }else if(isdigit(x)){
					if(!b){
						num++;
						b=true;
					}
				 sw=false;
			 }else{
				 sw=false;
				 b=false;
			 }
		 }else{
			 fo.put(pal+48); fo.put(',');fo.put(num+48); fo.put(10);
			 pal=0; num=0;
         }
	 }
	 f.close();
     fo.close();
  }
}

void __fastcall TForm3::Button13Click(TObject *Sender)
{
   if(OpenTextFileDialog1->Execute()){
	   CantPalAndNum(OpenTextFileDialog1->FileName);
   }
}
//---------------------------------------------------------------------------
//Modifica un archivo de texto de forma que se reemplace cada caracter
//numerico (digito) por su literal
AnsiString literal(char &x){
   AnsiString palabras[] = {"uno", "dos", "tres","cuatro","cinco","seis","siete","ocho","nueve"};

	if (x >= '1' && x <= '9')
        return palabras[x - '1'];  // convertir char a índice
    else
        return "fuera de rango";

}

void ReplaceChar(AnsiString nom){
 char x;    AnsiString nomArch="replace.txt";
 AnsiString lit;   byte i,p,n;
 fstream f(nom.c_str());
 ofstream fo(nomArch.c_str());
 if(!f.fail()){
	while(!f.eof()){
	   x=f.get();
	   lit="";
	   if(!f.eof()){
		   if(isdigit(x)){
			   lit=literal(x);
			   n=lit.Length();
			   for(i=1; i<=n; i++){
				  fo.put(lit[i]);
			   }
		   }else{
			   fo.put(x);
           }
	   }
	}
	f.close();
	fo.close();
	remove(nom.c_str());
	rename(nomArch.c_str(),nom.c_str());
 }
}
void __fastcall TForm3::Button14Click(TObject *Sender)
{
  // char num=Edit1->Text[1];
   //Edit2->Text=literal(num);
   if(OpenTextFileDialog1->Execute()){
	   ReplaceChar(OpenTextFileDialog1->FileName);
   }
}
//---------------------------------------------------------------------------
//la primera palabra en mayusculas y demas a minusculas
//proceso para convertir los nombres a mayusculas y el resto a minusculas
void MayusMinus2(char lin[]){
   Word i,n,p; boolean hallado=false;
   AnsiString may="QWERTYUIOPASDFGHJKLÑZXCVBNM";
   AnsiString min="qwertyuiopasdfghjklñzxcvbnm";
   n=strlen(lin);
   for(i=0;i<n; i++){
	  if(EsPalabra(lin[i])){
		if(!hallado){
		   if(EsPalabra(lin[i+1])&& lin[i+1]!=10){
			  //pone a mayusculas
			  p=min.Pos(lin[i]);
			  if(p>0){
				lin[i]=may[p];
			  }
		   }else{
				p=min.Pos(lin[i]);
				if(p>0){
				   lin[i]=may[p];
				}
			hallado=true;
		   }
		}else{
			//pone a minusculas
			p=may.Pos(lin[i]);
			if(p>0){
				lin[i]=min[p];
			}
		}


	  }
   }
}

//examen pregu2
/*
 hacer un algoritmo para generar un listado ordenado por nombre de mayor a menor,
 Ademas, en el listado el nombre debera aparecer en mayusculas y la direccion
 en minusculas
  LISTADO EXAMEN
  600,PEDRO,calle2,2/2/2002,356554
  700,MARTHA,calle5,5/5/2005,265865
  300,MARIAN,calle3,3/3/2003,321654
  200,JUAN,calle1,1/1/2001,584116
  500,JOSE,calle4,4/4/2004,1654843
*/

void modificar_archivo(AnsiString nom){
   AnsiString nuevo="D:\\POO\\inf210\\archivos_textos\\SALIDA12.txt";
   AnsiString linea; char lin[501];  bool hallado=false;
  fstream f(nom.c_str());
  ofstream fo(nuevo.c_str());
  if(!f.fail()){
	 while(!f.eof()){
		 f.getline(lin,500);
		 MayusMinus2(lin);
		 Word n=strlen(lin);
		 for(Word i=0;i<n; i++){
			 fo.put(lin[i]);
		 }
		 fo.put(10);
	 }
	 f.close();
     fo.close();
  }
}


void __fastcall TForm3::Button15Click(TObject *Sender)
{
  if(OpenTextFileDialog1->Execute()){
	  Edit1->Text=OpenTextFileDialog1->FileName;
	  modificar_archivo(OpenTextFileDialog1->FileName);
  }
}
//---------------------------------------------------------------------------


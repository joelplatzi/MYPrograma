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
void __fastcall TForm3::FormCreate(TObject *Sender)
{           //D:\POO\final
   ruta="D:\\POO\\final\\";
   nom="Alumnos.dat";
   AnsiString nomArch=ruta+nom;
   fstream f(nomArch.c_str(),ios::binary|ios::in);
   if(f.fail()){
	   f.open(nomArch.c_str(),ios::binary|ios::out);
   }
   f.close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::guardar1Click(TObject *Sender)
{
   RegAlumno reg;   AnsiString nomArch=ruta+nom;
   AnsiString aux;
   reg.cod=Edit1->Text.ToInt();
   aux=Edit2->Text;
   strcpy(reg.nom,aux.c_str());
   aux=Edit3->Text;
   strcpy(reg.dir,aux.c_str());
   reg.fecha.dia=Edit4->Text.ToInt();
   reg.fecha.mes=Edit5->Text.ToInt();
   reg.fecha.año=Edit6->Text.ToInt();
   fstream f(nomArch.c_str(),ios::binary|ios::app);
   f.write((char*)&reg,sizeof(reg));
   f.close();
   limpiar1Click(Sender);
   ShowMessage("Datos guardados");
}
//---------------------------------------------------------------------------
void __fastcall TForm3::limpiar1Click(TObject *Sender)
{
  Edit1->Text="";
  Edit2->Text="";
  Edit3->Text="";
  Edit4->Text="";
  Edit5->Text="";
  Edit6->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TForm3::listado1Click(TObject *Sender)
{
   RegAlumno reg; AnsiString nomArch=ruta+nom;  AnsiString nuevo=ruta+"listado1.txt";
   AnsiString linea;
   fstream f(nomArch.c_str(),ios::binary|ios::in);
   fstream fi(nuevo.c_str(),ios::out);
   if(!f.fail()){
	   while(!f.eof()){
			f.read((char*)&reg,sizeof(reg));
			if(!f.eof()){
				linea=reg.cod;
				linea=linea+","+reg.nom+","+reg.dir+","+reg.fecha.dia+"/"+reg.fecha.mes+"/"+reg.fecha.año;
				for(Word i=1; i<=linea.Length(); i++){
					  fi.put(linea[i]);
				}
				fi.put(10);
			}
	   }
	  f.close();
	  fi.close();
	  ShowMessage("listado generado");
   }
}
//---------------------------------------------------------------------------
//pregu1
/*
 Modificar el codi de todos los q cumplan con el siguiente parametro
 a) Su primer nombre empiezan con consonantes y terminar con vocal
 el codigo debe cambiar aumentando 5 al valor inicial
 200,juan,calle1,1/1/2001
400,pedro,calle2,2/2/2002
300,marian,calle3,3/3/2003
500,jose,calle4,4/4/2004
700,martha,calle5,5/5/2005
///////
200,juan,calle1,1/1/2001
405,pedro,calle2,2/2/2002
300,marian,calle3,3/3/2003
505,jose,calle4,4/4/2004
705,martha,calle5,5/5/2005
*/

bool vocal(char x){
	 AnsiString voc="aeiou";
   return voc.Pos(x)>0;
}
bool consonante(char x){
  AnsiString consonantes="qwrtyupsdfghjklñzxcvbnm";
  return consonantes.Pos(x)>0;
}
void modificar(AnsiString nomArch){
  RegAlumno reg;  AnsiString aux;    Cardinal n,p;
  fstream f(nomArch.c_str(),ios::in|ios::out|ios::binary);
  if(!f.fail()){
	  while(!f.eof()){
		   p=f.tellg();
		   f.read((char*)&reg,sizeof(reg));
		   if(!f.eof()){
			   aux=reg.nom;
			   if(consonante(aux[1])&& vocal(aux[aux.Length()])){
					 n=reg.cod;
					 reg.cod=n+5;
					 f.seekg(p);
					 f.write((char*)&reg,sizeof(reg));
                     f.seekg(p+sizeof(reg),ios::beg);
			   }
		   }
	  }
	  f.close();
	  ShowMessage("Datos modificados");
  }
}
void __fastcall TForm3::p11Click(TObject *Sender)
{
  AnsiString nomArch=ruta+nom;
   modificar(nomArch);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//ordenamiento por nombre   mayor  a menor

void __fastcall TForm3::xNombreMayMen1Click(TObject *Sender)
{
  AnsiString nomArch=ruta+nom;
  RegAlumno reg1,reg2;  Cardinal i,j,n;
  fstream f(nomArch.c_str(),ios::in|ios::out|ios::binary|ios::ate);
  if(!f.fail()){
	 n=f.tellg(); n=n-sizeof(reg1);
	 while(n>0){
		 j=i=0; f.seekg(i); f.read((char*)&reg1,sizeof(reg1));
		 i=i+sizeof(reg1);
		 while(i<=n){
			 f.seekg(i); f.read((char*)&reg2,sizeof(reg2));
			 if(reg2.nom[0]<reg1.nom[0]){
				  reg1=reg2;
				  j=i;
			 }
			 i=i+sizeof(reg2);
		 }
		 if(j!=n){
			 f.seekg(j); f.write((char*)&reg2,sizeof(reg2));
			 f.seekg(n); f.write((char*)&reg1,sizeof(reg1));
		 }
		 n=n-sizeof(reg1);
	 }
	 f.close();
	 ShowMessage("Indice por nombre ordenado");
  }
}
//---------------------------------------------------------------------------
//ordenamiento por nombre de menor a mayor

void __fastcall TForm3::xNombreMenMay1Click(TObject *Sender)
{
  RegAlumno r1,r2; Cardinal i,j,n;
  AnsiString nomArch=ruta+nom;
  fstream f(nomArch.c_str(),ios::in|ios::out|ios::binary|ios::ate);
  if(!f.fail()){
	 n=f.tellg(); n=n-sizeof(r1);
	 while(n>0){
		 j=i=0; f.seekg(i); f.read((char*)&r1,sizeof(r1));
		 i=i+sizeof(r1);
		 while(i<=n){
			 f.seekg(i); f.read((char*)&r2,sizeof(r2));
			 if(r2.nom[0]>r1.nom[0]){
				 r1=r2;
				 j=i;
			 }
			 i=i+sizeof(r2);
		 }
		 if(j!=n){
			 f.seekg(j); f.write((char*)&r2,sizeof(r2));
			 f.seekg(n);  f.write((char*)&r1,sizeof(r1));
		 }
		 n=n-sizeof(r1);
	 }
	 f.close();
	 ShowMessage("Ordenamiento por nombre ordenado");
  }
}
//---------------------------------------------------------------------------
 // ordenamiento por codigo mayor a menor
void __fastcall TForm3::xCodMayMenor1Click(TObject *Sender)
{
  RegAlumno r1,r2;  Cardinal i,j,n;
  AnsiString nomArch=ruta+nom;
  fstream f(nomArch.c_str(),ios::in|ios::out|ios::binary|ios::ate);
  if(!f.fail()){
	 n=f.tellg(); n=n-sizeof(r1);
	 while(n>0){
		j=i=0; f.seekg(i); f.read((char*)&r1,sizeof(r1));
		i=i+sizeof(r1);
		while(i<=n){
			f.seekg(i); f.read((char*)&r2,sizeof(r2));
			if(r2.cod<r1.cod){
				r1=r2;
				j=i;
			}
			i=i+sizeof(r2);
		}
		if(j!=n){
			f.seekg(j); f.write((char*)&r2,sizeof(r2));
			f.seekg(n);  f.write((char*)&r1,sizeof(r1));
		}
		n=n-sizeof(r1);
	 }
	 f.close();
	 ShowMessage("Codigo ordenado");
  }

}
//---------------------------------------------------------------------------
// ordenamiento por codigo de menor a mayor


void __fastcall TForm3::xCodMenMay1Click(TObject *Sender)
{
  RegAlumno reg1,reg2; Cardinal i,j,n;
  AnsiString nomArch=ruta+nom;
  fstream f(nomArch.c_str(),ios::in|ios::out|ios::binary|ios::ate);
  if(!f.fail()){
	  n=f.tellg(); n=n-sizeof(reg1);
	  while(n>0){
		 j=i=0; f.seekg(i); f.read((char*)&reg1,sizeof(reg1));
		 i=i+sizeof(reg1);
		 while(i<=n){
			f.seekg(i); f.read((char*)&reg2,sizeof(reg2));
			if(reg2.cod>reg1.cod){
				reg1=reg2;
				j=i;
			}
			i=i+sizeof(reg2);
		 }
		 if(j!=n){
			  f.seekg(j); f.write((char*)&reg2,sizeof(reg2));
			  f.seekg(n); f.write((char*)&reg1,sizeof(reg1));
		 }
		 n=n-sizeof(reg1);
	  }
	  f.close();
	  ShowMessage("codigo ordenado");
  }
}
//---------------------------------------------------------------------------

/*
2.Hacer un algoritmo para generar un listado ordenado por nombre de
mayor a menor.Ademas ,en el listado,el nombre debera aparecer en mayusculas
y la direccion en minusculas
  LISTADO EXAMEN
200,PEDRO,calle1,1/1/2001
400,MARTHA,calle2,2/2/2002
300,MARIAN,calle3,3/3/2003
500,JUAN,calle4,4/4/2004
700,JOSE,calle5,5/5/2005
*/
void ToLower(AnsiString &cad){
   AnsiString may="QWERTYUIOPASDFGHJKLÑZXCVBNM";
   AnsiString min="qwertyuiopasdfghjklñzxcvbnm";
   byte p;
   byte i=1;
   while(i<=cad.Length()){
	 // char x=cad[i];
	  p=min.Pos(cad[i]);
	// p=may.Pos(x) ;
	   if(p>0){
		   cad[i]=may[p];
	   }
	   i++;
   }
}
//convierte solo el nombre a mayuscula
void convertir_name_mayus(AnsiString name){
  RegAlumno reg;    AnsiString nombre;        Cardinal p;
  fstream f(name.c_str(),ios::in|ios::out|ios::binary);
  if(!f.fail()){
	   while(!f.eof()){
			p=f.tellg();
			f.read((char*)&reg,sizeof(reg));
			if(!f.eof()){
				nombre=reg.nom;
				ToLower(nombre);
				strcpy(reg.nom,nombre.c_str());
				f.seekg(p);
				f.write((char*)&reg,sizeof(reg));
				f.seekg(p+sizeof(reg),ios::beg);  //posicionando el puntero
			}                                     //como si fuera secuencial
	   }
	   f.close();
	   ShowMessage("datos modificados");
  }

}

void __fastcall TForm3::p21Click(TObject *Sender)
{
  AnsiString nomArch=ruta+nom;
  convertir_name_mayus(nomArch);
}
//---------------------------------------------------------------------------
 //muetre la fecha si esta en el rango del dia,mes,año
void __fastcall TForm3::fecha1Click(TObject *Sender)
{
  RegAlumno reg; AnsiString nomArch=ruta+nom;
  AnsiString linea;   AnsiString nuevo=ruta+"listado7.txt";
  fstream fd(nomArch.c_str(),ios::in|ios::binary);
  fstream t(nuevo.c_str(),ios::out);
  if(!fd.fail()){
	  while(!fd.eof()){
		   fd.read((char*)&reg,sizeof(reg));
		   if(!fd.eof()){
			  if((2025-reg.fecha.año>20)){
				   linea=IntToStr(reg.cod)+","+reg.nom+","+reg.dir+","+reg.fecha.dia+"/"+reg.fecha.mes+"/"+reg.fecha.año;
				   for(Word i=1; i<=linea.Length(); i++){
						  t.put(linea[i]);
				   }
				   t.put(10);
			  }else if(2025-reg.fecha.año==20){
				  if(reg.fecha.mes>11){
					   linea=IntToStr(reg.cod)+","+reg.nom+","+reg.dir+","+reg.fecha.dia+"/"+reg.fecha.mes+"/"+reg.fecha.año;
					   for(Word i=1; i<=linea.Length(); i++){
							  t.put(linea[i]);
					   }
					   t.put(10);
				  }else if(reg.fecha.mes==11){
					  if(reg.fecha.dia>26){
						  linea=IntToStr(reg.cod)+","+reg.nom+","+reg.dir+","+reg.fecha.dia+"/"+reg.fecha.mes+"/"+reg.fecha.año;
						   for(Word i=1; i<=linea.Length(); i++){
								 t.put(linea[i]);
						   }
						   t.put(10);
					  }
				  }
			  }
		   }
	  }
	  fd.close(); t.close();
	  ShowMessage("Listado generado");
  }
}
//---------------------------------------------------------------------------
 /*2.hacer un algoritmo para modificar la fecha de todos los estudiantes
   de forma que se aumente un dia a la fecha actual
  LISTADO EXAMEN
200,PEDRO,calle1,1/2/2000
400,MARTHA,calle2,31/1/2001
300,MARIAN,calle3,31/12/2002
500,JUAN,calle4,5/8/2003
--------------------------------------
  LISTADO EXAMEN
200,PEDRO,calle1,2/2/2000
400,MARTHA,calle2,1/2/2001
300,MARIAN,calle3,1/1/2003
500,JUAN,calle4,6/8/2003
 */

void fecha_dia(AnsiString dia){
  RegAlumno reg;  byte n;    Cardinal p;
  fstream f(dia.c_str(),ios::in|ios::out|ios::binary);
  if(!f.fail()){
	  while(!f.eof()){
		  p=f.tellg();
		  f.read((char*)&reg,sizeof(reg));
		  if(!f.eof()){
			 n=reg.fecha.dia;
			 f.seekg(p);
			 if(n<31){
				 reg.fecha.dia=n+1;
				 //f.seekg(p);
				 f.write((char*)&reg,sizeof(reg));
				 f.seekg(p+sizeof(reg),ios::beg);
			 }else if(n==31 && reg.fecha.mes<12){
				reg.fecha.dia=1;
				reg.fecha.mes=reg.fecha.mes+1;
			   //	f.seekg(p);
				f.write((char*)&reg,sizeof(reg));
				f.seekg(p+sizeof(reg),ios::beg);
			 }else if(n==31 && reg.fecha.mes==12){
				 reg.fecha.dia=1;
				 reg.fecha.mes=1;
				 reg.fecha.año=reg.fecha.año+1;
				 //f.seekg(p);
				 f.write((char*)&reg,sizeof(reg));
                 f.seekg(p+sizeof(reg),ios::beg);
			 }
		  }
	  }
	  f.close();
  }
}
void __fastcall TForm3::fecha1dia1Click(TObject *Sender)
{
   AnsiString nomArch=ruta+nom;
   fecha_dia(nomArch);
}
//---------------------------------------------------------------------------


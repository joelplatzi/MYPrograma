//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include<fstream>
//---------------------------------------------------------------------------
struct TFecha{
	byte dia; //1byte
	byte mes; //1byte
	Word año; //2 bytes
};  //4 bytes
struct  RegAlumno{
	Word cod;  //2 bytes
	char nom[21];
	char dir[21];
	TFecha fecha; //4 bytes
};  //
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TLabel *Label6;
	TEdit *Edit6;
	TEdit *Edit7;
	TMainMenu *MainMenu1;
	TMenuItem *alumnosdat1;
	TMenuItem *guardar1;
	TMenuItem *limpiar1;
	TMenuItem *listado1;
	TMenuItem *pregu11;
	TMenuItem *p11;
	TMenuItem *ordenamientos1;
	TMenuItem *xNombreMayMen1;
	TMenuItem *xNombreMenMay1;
	TMenuItem *xCodMayMenor1;
	TMenuItem *xCodMenMay1;
	TMenuItem *p21;
	TMenuItem *fechasqueestenenelrango1;
	TMenuItem *fecha1;
	TMenuItem *fecha1dia1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall guardar1Click(TObject *Sender);
	void __fastcall limpiar1Click(TObject *Sender);
	void __fastcall listado1Click(TObject *Sender);
	void __fastcall p11Click(TObject *Sender);
	void __fastcall xNombreMayMen1Click(TObject *Sender);
	void __fastcall xNombreMenMay1Click(TObject *Sender);
	void __fastcall xCodMayMenor1Click(TObject *Sender);
	void __fastcall xCodMenMay1Click(TObject *Sender);
	void __fastcall p21Click(TObject *Sender);
	void __fastcall fecha1Click(TObject *Sender);
	void __fastcall fecha1dia1Click(TObject *Sender);
private:	// User declarations
  AnsiString nom;
  AnsiString ruta;
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif

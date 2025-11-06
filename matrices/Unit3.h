//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TStringGrid *StringGrid1;
	TMainMenu *MainMenu1;
	TMenuItem *matriz1;
	TMenuItem *cargarmatriz1;
	TMenuItem *cargarNivel21;
	TMenuItem *pregunta11;
	TEdit *Edit3;
	void __fastcall cargarmatriz1Click(TObject *Sender);
	void __fastcall cargarNivel21Click(TObject *Sender);
	void __fastcall pregunta11Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif

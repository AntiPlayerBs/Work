// ---------------------------------------------------------------------------

#ifndef SettingsH
#define SettingsH
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components

	TComboBox *ComboBox1;
	TLabel *Label1;
	TComboBox *ComboBox2;
	TLabel *Label2;
	TButton *Button1;
	TButton *Button2;

	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);

private: // User declarations
		public : // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif

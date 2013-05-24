// ---------------------------------------------------------------------------

#ifndef mainH
#define mainH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Grids.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>

// ---------------------------------------------------------------------------
class TMainForm : public TForm {
__published: // IDE-managed Components

	TButton *Button1;
	TMemo *Memo1;
	TMemo *Memo2;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *COM1;
	TMenuItem *Cghfdrf1;
	TMenuItem *N5;
	TStringGrid *Grid1;
	TChart *Chart;
	TLineSeries *Series1;
	TProgressBar *ProgressBar1;
	TLabel *Label1;
	TMemo *Console;
	TSaveTextFileDialog *Save;
	TMenuItem *N6;
	TOpenTextFileDialog *Open;

	void __fastcall Button1Click(TObject *Sender);
	void __fastcall COM1Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);

private: // User declarations
		public : // User declarations

	TThread *run_scan;
	bool potok_b;

	__fastcall TMainForm(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
// ---------------------------------------------------------------------------
#endif

unsigned int Check_CRC2(unsigned char *Massive, unsigned char Bytes) {

	int Temp_Register;
	unsigned char i, j;

	Temp_Register = 0xFFFF;

	for (j = 0x00; j < Bytes; j++) {
		Temp_Register ^= *(Massive + j);
		for (i = 0x00; i < 0x08; i++) {
			if (Temp_Register & 0x0001 == 0x0001) {
				Temp_Register = ((Temp_Register >> 1) & 0x7FFF);
				Temp_Register = (Temp_Register ^ 0xA001);
			}
			else {
				Temp_Register = ((Temp_Register >> 1) & 0x7FFF);
			}
		}
	}

	// Функция возвращает значение CRC (регистр)
	return Temp_Register;

} // end void Check_CRC

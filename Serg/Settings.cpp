// ---------------------------------------------------------------------------

#include <vcl.h>
#include "IniFiles.hpp"
#pragma hdrstop

#include "Settings.h"
#include "main.h"
#include "potok.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	TIniFile *Ini = new TIniFile(ExtractFilePath(Application->ExeName) +
		"settings.ini");
	Ini->EraseSection("COM-ports");
	for (int i = 0; i < 256; i++) {
		String portName = "\\\\.\\COM" + IntToStr(i);
		HANDLE search = CreateFile(portName.c_str(),
			GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

		if (search != INVALID_HANDLE_VALUE) {
			Ini->WriteString("COM-ports", "COM" + IntToStr(i), IntToStr(i));
			CloseHandle(search);
		}
		Ini->ReadSection("COM-ports", ComboBox2->Items);
		ComboBox1->Text = Ini->ReadString("Port", "BaudRate", "9600");
		ComboBox2->Text = Ini->ReadString("Port", "Addr", "COM1");
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	TIniFile *Ini = new TIniFile(ExtractFilePath(Application->ExeName) +
		"settings.ini");
	Ini->WriteString("Port", "Addr", ComboBox2->Text);
	Ini->WriteString("Port", "BaudRate", ComboBox1->Text);
	Close();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	Close();
}
// ---------------------------------------------------------------------------

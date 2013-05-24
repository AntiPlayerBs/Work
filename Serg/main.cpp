// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "potok.h"
#include "Settings.h"
#include "IniFiles.hpp"
#include "chart.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

// ---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner) {
	TIniFile *Ini = new TIniFile(ExtractFilePath(Application->ExeName) +
		"settings.ini");
	Grid1->Cells[0][0] = "Дата";
	Grid1->Cells[1][0] = "Концентрация";
	Series1->Clear();
	Console->Lines->Add("Программа загружена...");
	Console->Lines->Add("Выбран порт " + Ini->ReadString("Port", "Addr",
		"COM1"));
	Console->Lines->Add("Скорость " + Ini->ReadString("Port", "BaudRate",
		"9600"));

}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender) {
	if (Button1->Caption == "Стоп") {
		Button1->Caption = "Чтение";
		Console->Lines->Add("Считывание остановлено пользователем");
		potok_b = false;

	}
	else {
		if (Button1->Caption == "Чтение") {
			Grid1->ColCount = 2;
			Grid1->RowCount = 2;
			Grid1->Cells[0][1] = "";
			Grid1->Cells[1][1] = "";
			Button1->Caption = "Стоп";
			Series1->Clear();
			Console->Lines->Add("Считывание началось");
			ProgressBar1->Position = 0;
			ProgressBar1->Max = 256;
			potok_b = true;
			potok *Thr = new potok(false);
		}
	}

}

// ---------------------------------------------------------------------------
void __fastcall TMainForm::COM1Click(TObject *Sender) {
	Form1->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::N2Click(TObject *Sender) {
	TStringList *savetable = new TStringList;

	if (Save->Execute()) {
		for (int i = 0; i < Grid1->RowCount; i++) {
			savetable->Add(Grid1->Rows[i]->DelimitedText);
		}
		savetable->SaveToFile(Save->FileName + ".tx1");
		Console->Lines->Add("Сохранен файл " + Save->FileName);
		delete savetable;
	}
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::N3Click(TObject *Sender) {
	Close();
}
// ---------------------------------------------------------------------------

void __fastcall TMainForm::N6Click(TObject *Sender) {
	TStringList *opentable = new TStringList;
	String buftable2;
	if (Open->Execute())

	{
		opentable->LoadFromFile(Open->FileName);
		Grid1->RowCount = opentable->Count;
		Console->Lines->Add("Открыт файл " + Open->FileName);
		for (int i = 0; i < Grid1->RowCount; i++) {
			Grid1->Rows[i]->DelimitedText = opentable->Strings[i];
		}
		delete opentable;
		Series1->Clear();
		chart *Thr = new chart(false);
		Console->Lines->Add("График построен из файла " + Open->FileName);

	}
}
// ---------------------------------------------------------------------------

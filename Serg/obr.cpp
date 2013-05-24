// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "obr.h"
#include "potok.h"
#include "main.h"
#include "chart.h"
#pragma package(smart_init)
String maina;
String temp;
String temp2;
int go;
int temphex;
float go1;
// ---------------------------------------------------------------------------

// Important: Methods and properties of objects in VCL can only be
// used in a method called using Synchronize, for example:
//
// Synchronize(&UpdateCaption);
//
// where UpdateCaption could look like:
//
// void __fastcall obr::UpdateCaption()
// {
// Form1->Caption = "Updated in a thread";
// }
// ---------------------------------------------------------------------------

__fastcall obr::obr(bool CreateSuspended) : TThread(CreateSuspended) {
}

// ---------------------------------------------------------------------------
void __fastcall obr::Execute() {
	for (int i = 0; i < MainForm->Memo1->Lines->Count - 1; i++) {
		if (!MainForm->potok_b) {
			return;
		}
		Synchronize(&UpdateProgress);
		if (MainForm->Memo1->Lines->Strings[i] != "FFFFFFFFFFFFFFFF") {
			if (!MainForm->potok_b) {
				return;
			}
			////Обработка концентрации

			temp = MainForm->Memo1->Lines->Strings[i][1];
			temp = temp + MainForm->Memo1->Lines->Strings[i][2];
			temp2 = MainForm->Memo1->Lines->Strings[i][3];
			temp2 = temp2 + MainForm->Memo1->Lines->Strings[i][4];
			// temphex=StrToInt(temp2);
			// temp2=0x100;

			temp = temp2 + temp;
			temp = "0x" + temp;
			go = StrToInt(temp);
			go1 = go;
			if (!MainForm->potok_b) {
				return;
			}
			if (MainForm->Grid1->Cells[1][1] != "") {
				Synchronize(&UpdateCount);
			}
			Synchronize(&UpdateConcentr);
			if (!MainForm->potok_b) {
				return;
			}
			////Обработка даты и времени
			temp = MainForm->Memo1->Lines->Strings[i][13];
			temp = "0x" + temp;
			go = StrToInt(temp);
			go = go + 2013;
			maina = IntToStr(go) + "г ";
			temp = MainForm->Memo1->Lines->Strings[i][14];
			temp = "0x" + temp;
			go = StrToInt(temp);
			maina = IntToStr(go) + "." + maina;
			temp = MainForm->Memo1->Lines->Strings[i][11];
			temp = temp + MainForm->Memo1->Lines->Strings[i][12];
			temp = "0x" + temp;
			go = StrToInt(temp);
			maina = IntToStr(go) + "." + maina;
			if (!MainForm->potok_b) {
				return;
			}

			temp = MainForm->Memo1->Lines->Strings[i][9];
			temp = temp + MainForm->Memo1->Lines->Strings[i][10];
			temp = "0x" + temp;
			go = StrToInt(temp);
			maina = maina + IntToStr(go) + ":";
			if (!MainForm->potok_b) {
				return;
			}
			temp = MainForm->Memo1->Lines->Strings[i][7];
			temp = temp + MainForm->Memo1->Lines->Strings[i][8];
			temp = "0x" + temp;
			go = StrToInt(temp);
			maina = maina + IntToStr(go) + ":";
			if (!MainForm->potok_b) {
				return;
			}
			temp = MainForm->Memo1->Lines->Strings[i][5];
			temp = temp + MainForm->Memo1->Lines->Strings[i][6];
			temp = "0x" + temp;
			go = StrToInt(temp);
			maina = maina + IntToStr(go);
			Synchronize(&UpdateGrid);
			if (!MainForm->potok_b) {
				return;
			}
		}
	}
TStringList *SL = new TStringList;


for (int i=1; i < MainForm->Grid1->RowCount; i++)
	{
	SL->Add(MainForm->Grid1->Rows[i]->DelimitedText);
    }

SL->Sort();

for (int i=1; i < MainForm->Grid1->RowCount; i++)
    {
	 MainForm->Grid1->Rows[i]->DelimitedText = SL->Strings[i-1];
    }
delete SL;
	Synchronize(&UpdateLabel);
	chart *Thr = new chart(false);
}
// ---------------------------------------------------------------------------

void __fastcall obr::UpdateGrid() {
	MainForm->Grid1->Cells[0][MainForm->Grid1->RowCount - 1] = maina;
}

void __fastcall obr::UpdateGrid2() {
	MainForm->Grid1->Cells[1][MainForm->Grid1->RowCount - 1] = IntToStr(go);
}

void __fastcall obr::UpdateCount() {
	MainForm->Grid1->RowCount++;
}

void __fastcall obr::UpdateProgress() {
	MainForm->ProgressBar1->Position = MainForm->ProgressBar1->Position + 1;

}

void __fastcall obr::UpdateLabel() {

	MainForm->Label1->Caption = "Выполнено!";

}

void __fastcall obr::UpdateConcentr() {

	MainForm->Grid1->Cells[1][MainForm->Grid1->RowCount - 1] =
		FloatToStrF(go1 / 100, ffGeneral, 6, 2);

}

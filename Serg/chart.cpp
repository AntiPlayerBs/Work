// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "chart.h"
#include "obr.h"
#include "potok.h"
#include "main.h"
#pragma package(smart_init)
// ---------------------------------------------------------------------------

// Important: Methods and properties of objects in VCL can only be
// used in a method called using Synchronize, for example:
//
// Synchronize(&UpdateCaption);
//
// where UpdateCaption could look like:
//
// void __fastcall chart::UpdateCaption()
// {
// Form1->Caption = "Updated in a thread";
// }
// ---------------------------------------------------------------------------
String gph;
String gph2;

__fastcall chart::chart(bool CreateSuspended) : TThread(CreateSuspended) {
}

// ---------------------------------------------------------------------------
void __fastcall chart::Execute() {

	for (int i = 1; i < MainForm->Grid1->RowCount - 1; i++) {
		gph = MainForm->Grid1->Cells[0][i];
		gph2 = MainForm->Grid1->Cells[1][i];
		MainForm->Series1->AddXY(i, gph2.ToDouble(), gph);
	}
	Synchronize(&Update1);
}

void __fastcall chart::Update1() {
	MainForm->Button1->Caption = "Чтение";
}

// ---------------------------------------------------------------------------

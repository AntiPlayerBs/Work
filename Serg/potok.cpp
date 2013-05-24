// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "IniFiles.hpp"

#include "potok.h"
#include "main.h"
#include "obr.h"
#pragma package(smart_init)
HANDLE condev2;
DWORD feedback;
String bufread;
String bufread2;
int bytes;
// ---------------------------------------------------------------------------

// Important: Methods and properties of objects in VCL can only be
// used in a method called using Synchronize, for example:
//
// Synchronize(&UpdateCaption);
//
// where UpdateCaption could look like:
//
// void __fastcall potok::UpdateCaption()
// {
// Form1->Caption = "Updated in a thread";
// }
// ---------------------------------------------------------------------------

__fastcall potok::potok(bool CreateSuspended) : TThread(CreateSuspended) {
}

// ---------------------------------------------------------------------------
void __fastcall potok::Execute() {
	bytes = 0;
	MainForm->potok_b = true;
	DCB portDcb;
	COMMTIMEOUTS portTO;
	portTO.ReadIntervalTimeout = 200;
	portTO.ReadTotalTimeoutMultiplier = 200;
	portTO.ReadTotalTimeoutConstant = 500;
	portTO.WriteTotalTimeoutMultiplier = 200;
	portTO.WriteTotalTimeoutConstant = 200;

	TIniFile *Ini = new TIniFile(ExtractFilePath(Application->ExeName) +
		"settings.ini");
	const String portName = "\\\\.\\" + Ini->ReadString("Port", "Addr", "COM1");
	int boudrate = Ini->ReadInteger("Port", "BaudRate", 9600);
	condev2 = CreateFile(portName.c_str(),
		// вот здесь сраный капец, не забываем правильно переводить перменные. Типизированные языки такие типизированные
		GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (!MainForm->potok_b) {
		CloseHandle(condev2);
		return;
	}
	if (!GetCommState(condev2, &portDcb)) {
		CloseHandle(condev2);
		condev2 = INVALID_HANDLE_VALUE;
		CloseHandle(condev2);
		MainForm->Console->Lines->Add
			("Порт закрыт. Не удалось инициировать опрос концентрации.");
		return;
	}

	// устанавливаем скорость
	portDcb.BaudRate = boudrate;
	portDcb.fBinary = true;
	portDcb.fParity = false; // проверка четности
	portDcb.Parity = NOPARITY; // Установка типа четности
	portDcb.ByteSize = 8;
	portDcb.StopBits = ONESTOPBIT; // 2 бита
	portDcb.fDtrControl = DTR_CONTROL_DISABLE;
	portDcb.fRtsControl = RTS_CONTROL_DISABLE;

	if (!SetCommState(condev2, &portDcb)) {
		CloseHandle(condev2);
		condev2 = INVALID_HANDLE_VALUE;

		MainForm->Console->Lines->Add
			("Порт закрыт. Не удалось инициировать опрос концентрации.");
		return;
	}
	if (!SetCommTimeouts(condev2, &portTO)) {
		CloseHandle(condev2);
		condev2 = INVALID_HANDLE_VALUE;
		MainForm->Console->Lines->Add
			("Порт закрыт. Не удалось инициировать опрос концентрации.");
		return;
	}

	if (condev2 == INVALID_HANDLE_VALUE) {
		CloseHandle(condev2);
		MainForm->Console->Lines->Add
			("Порт закрыт. Не удалось инициировать опрос концентрации.");
		return;
	}
	else {
		if (!MainForm->potok_b) {
			CloseHandle(condev2);
			return;
		}
		if (!PurgeComm(condev2, PURGE_RXCLEAR)) {
			Synchronize(&UpdateMemo2);
		}; // clear input   buffer
		if (!PurgeComm(condev2, PURGE_TXCLEAR)) {
			Synchronize(&UpdateMemo2);
		}; // clear outpu

		for (int i = 0; i < 256; i++) {
			if (!MainForm->potok_b) {
				CloseHandle(condev2);
				return;
			}

			for (int j = 0; j < 2; j++) {

				if (!MainForm->potok_b) {
					CloseHandle(condev2);
					return;
				}

				unsigned char buf_write[8] = {
					0x01, 0x41, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00};
				int h = 1;

				buf_write[0] = (unsigned char)(h);
				buf_write[2] = (unsigned char)(i);
				buf_write[3] = (unsigned char)(j * 0x80);
				unsigned int CRC;
				CRC = Check_CRC2(&buf_write[0x00], 6);
				buf_write[7] = (unsigned char)((0xFF00 & CRC) >> 8);
				buf_write[6] = (unsigned char)(0x00FF & CRC);
				unsigned char buf_read[133];
				bufread = "";

				WriteFile(condev2, buf_write, 8, &feedback, NULL);

				ReadFile(condev2, buf_read, 133, &feedback, NULL);
				if (feedback != 133) {

					bufread = "Прочитано неверное количество байт!";
					Synchronize(&UpdateBuffMemo2);
					bufread = "Проверьте порт!";
					Synchronize(&UpdateBuffMemo2);
					Synchronize(&UpdateButton);
					CloseHandle(condev2);
					return;

				}

				for (int k = 3; k < 131; k++) {
					if (!MainForm->potok_b) {
						CloseHandle(condev2);
						return;
					}

					if (((k - 3) % 8 == 0) && (k != 3)) {

						if (!MainForm->potok_b) {
							return;
						}
						Synchronize(&UpdateBuffMemo);
						bufread = "";

					}

					bufread = bufread + "" + IntToHex(buf_read[k], 2);
					if (i == 255 && j == 1 && k == 130) {
						bufread = "System info";
						Synchronize(&UpdateBuffMemo);
						// Synchronize(&UpdateProgress);
					}

				}

			}
			bytes = bytes + 256;
			Synchronize(&UpdateProgress);
		}
		if (!MainForm->potok_b) {
			CloseHandle(condev2);
			return;
		}

	}

	CloseHandle(condev2);
	Synchronize(&UpdateProgressEnd);
	obr *Thr = new obr(false);

}

void __fastcall potok::UpdateBuffMemo() {
	MainForm->Memo1->Lines->Add(bufread);
}

void __fastcall potok::UpdateBuffMemo2() {
	MainForm->Console->Lines->Add(bufread2);
}

void __fastcall potok::UpdateMemo2() {
	MainForm->Memo2->Lines->Add("Не очищается!");
}

void __fastcall potok::UpdateProgress() {
	MainForm->ProgressBar1->Position = MainForm->ProgressBar1->Position + 1;
	if (bytes > 4096) {
		MainForm->Label1->Caption = "Получено: " + IntToStr(bytes / 1024)
			+ " KБ";
	}
	else {
		MainForm->Label1->Caption = "Получено: " + IntToStr(bytes) + " Байт";
	}

}

void __fastcall potok::UpdateProgressEnd() {
	MainForm->ProgressBar1->Position = 0;
	MainForm->ProgressBar1->Max = MainForm->Memo1->Lines->Count;
	MainForm->Label1->Caption = "Обработка";

}

void __fastcall potok::UpdateButton() {
	MainForm->Button1->Caption = "RUN";
}
// ---------------------------------------------------------------------------

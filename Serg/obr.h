// ---------------------------------------------------------------------------

#ifndef obrH
#define obrH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>

// ---------------------------------------------------------------------------
class obr : public TThread {
private:
protected:
	void __fastcall Execute();

public:
	__fastcall obr(bool CreateSuspended);
	void __fastcall obr::UpdateGrid();
	void __fastcall obr::UpdateGrid2();
	void __fastcall obr::UpdateCount();
	void __fastcall obr::UpdateProgress();
	void __fastcall obr::UpdateLabel();
	void __fastcall obr::UpdateConcentr();
};
// ---------------------------------------------------------------------------
#endif

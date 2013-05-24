// ---------------------------------------------------------------------------

#ifndef chartH
#define chartH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>

// ---------------------------------------------------------------------------
class chart : public TThread {
private:
protected:
	void __fastcall Execute();

public:
	__fastcall chart(bool CreateSuspended);
	void __fastcall chart::Update1();
	void __fastcall chart::Update2();
};
// ---------------------------------------------------------------------------
#endif

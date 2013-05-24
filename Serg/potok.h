// ---------------------------------------------------------------------------

#ifndef potokH
#define potokH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>

// ---------------------------------------------------------------------------
class potok : public TThread {
private:
protected:
	void __fastcall Execute();

public:
	__fastcall potok(bool CreateSuspended);
	void __fastcall potok::UpdateBuffMemo();
	void __fastcall potok::UpdateBuffMemo2();
	void __fastcall potok::UpdateMemo2();
	void __fastcall potok::UpdateProgress();
	void __fastcall potok::UpdateProgressEnd();
	void __fastcall potok::UpdateButton();

};
// ---------------------------------------------------------------------------
#endif

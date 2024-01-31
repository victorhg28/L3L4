#include "L3L4.h"

comandos_L3L4::comandos_L3L4()
{
	CtrlLayout(*this, "L3L4");
	
	/*
	date1 ^= date2 ^= [=] {
		result = IsNull(date1) || IsNull(date2) ? "" :
		         Format("There is %d day(s) between %` and %`", abs(Date(~date1) - Date(~date2)), ~date1, ~date2);
	};
	*/
	//miTexto.SetData("asdasdass");
	btn_1 <<= THISBACK(Click);
}

void comandos_L3L4::Click(){
	funcion();
}

void comandos_L3L4::funcion()
{
	PromptOK("generic text");
}

GUI_APP_MAIN
{
	comandos_L3L4().Run();
}

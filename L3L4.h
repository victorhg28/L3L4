#ifndef _mi_header
#define _mi_header

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <L3L4/L3L4.lay>
#include <CtrlCore/lay.h>

class comandos_L3L4 : public Withmi_layout<TopWindow> {
public:
	typedef comandos_L3L4 CLASSNAME;
	void funcion();
	void Click();
	comandos_L3L4();
};

#endif

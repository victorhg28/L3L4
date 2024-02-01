# include "L3L4.h"
# include "objetos.h"
#include <typeinfo>

#include <iostream>
#include <fstream>
#include <string>

#ifndef header_funciones
	#define header_funciones
	#include "funciones.h"
#endif

#ifndef header_objetos
	#define header_objetos
	#include "objetos.h"
#endif

using namespace std;

comandos_L3L4::comandos_L3L4()
{
	CtrlLayout(*this, "L3L4");
	btn_1 <<= THISBACK(Click);
}

void comandos_L3L4::Click(){
	
	
	//f_titok_r123123_001
	
	//struct
	nombreFiltro nFiltro;
	
	nFiltro.pre = "f_";
	nFiltro.nombre = (String)gui_nomServ.GetData();
	nFiltro.req = "_r"+FormatInteger(gui_numReq);
	nFiltro.num_auto = "12";
	
	nFiltro.resultado = nFiltro.pre;
	nFiltro.resultado += nFiltro.nombre;
	nFiltro.resultado += nFiltro.req;
	nFiltro.resultado += "_"+nFiltro.num_auto;
	
	gui_resultado.SetText(nFiltro.resultado);
	
}


GUI_APP_MAIN{
	comandos_L3L4().Run();
}

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
	//nombreFiltro nFiltro;
	
	String Str_acum;
	
	//probando num requeriString(gui_numReqmiento
	//gui_resultado.SetText(FormatInteger(gui_numReq));
	
	//probando nombre (EditString)
	//gui_resultado.SetText(Format(gui_nomServ));
	//gui_resultado.SetText((String)gui_nomServ.GetData());
	
	Str_acum = "f_"+(String)gui_nomServ.GetData()+"_r"+FormatInteger(gui_numReq)+"__01";
	gui_resultado.SetText(Str_acum);
	
	//(gui_nomServ));
	
	
	
	
	//f_titok_r123123_001
	//nFiltro.pre = "f_";
	//nFiltro.nombre = (String)gui_nomServ.GetData();
	//nFiltro.req = (String)gui_numReq.GetData();
	//nombre.num_auto = 123123;
	//nFiltro.resultado = nFiltro.pre + nFiltro.nombre + "_r" + nFiltro.req +"_porAhoraSinNumeracion";
	
	//String str_prompt = nFiltro.resultado;
	//nFiltro.resultado.Cat(nFiltro.pre);
	
	//std::string adasdasd="asd";
	
	//PromptOK((String)nFiltro.resultado);
	//PromptOK();
	//gui_resultado.SetText("nop");
	
	//String abc = ""+nFiltro.resultado;
	//gui_resultado.SetText(abc);
	
	//PromptOK( (String)gui_nomServ.GetData()+"asdasd" );
	
	
	
	//gui_nomServ.GetData();
	
	//typeid(gui_nomServ.GetData()).name();		//N3Upp5ValueE
	//String aka="_"; //N3Upp6StringE
	
	//PromptOK(typeid(gui_nomServ.GetData()).name());
	//PromptOK( (String)gui_nomServ.GetData()+"asdasd" );
	//PromptOK(   typeid(aka).name()   );
	
	/*
	String parte1 = "ADD FILTER:FILTERNAME=\"";
	String parte3 = "\",L34PROTTYPE=STRING,L34PROTOCOL=ANY,SVRIPMODE=IP,SVRIP=\"";// más IP
	String parte4 = "\",SVRIPMASKTYPE=LENGTHTYPE,SVRIPMASKLEN=";
	//String mascara_aux= func_sacar_mascara(s_ipEnBruto);
	String mascara_aux="noFuncional_por_ahora";
	//string parte5 = ",MSSTARTPORT=0,MSENDPORT=65535,SVRSTARTPORT=0,SVRENDPORT=65535;";
	String parte5 = ",MSSTARTPORT=0,MSENDPORT=65535,SVRSTARTPORT=";
	String parte6 = ",SVRENDPORT=";
	
	//PARA PUERTO
	int num_aux=gui_puerto.GetData();;
	string str_aux=to_string(num_aux);
	
	String aux;
	aux = parte1+"nombre_generico"+parte3+"ip_generica"+parte4+mascara_aux+parte5+str_aux+parte6+str_aux+";";

	PromptOK(aux);
	
	
	
	//f_titok_r123123_001
	*/
}


GUI_APP_MAIN{
	comandos_L3L4().Run();
}

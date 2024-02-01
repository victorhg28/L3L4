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
	//String Str_nombreFiltro();
};

struct nombreFiltro{
	String pre;
	String nombre;
	String req;
	String num_auto;
	String resultado;
};


/*
class comando{
	public:
	//parametros
	String parte1 = "ADD FILTER:FILTERNAME=\"";
	String parte3 = "\",L34PROTTYPE=STRING,L34PROTOCOL=ANY,SVRIPMODE=IP,SVRIP=\"";// más IP
	String parte4 = "\",SVRIPMASKTYPE=LENGTHTYPE,SVRIPMASKLEN=";
	//String mascara_aux= func_sacar_mascara(s_ipEnBruto);
	String mascara_aux="noFuncional_por_ahora";
	//string parte5 = ",MSSTARTPORT=0,MSENDPORT=65535,SVRSTARTPORT=0,SVRENDPORT=65535;";
	String parte5 = ",MSSTARTPORT=0,MSENDPORT=65535,SVRSTARTPORT=";
	String parte6 = ",SVRENDPORT=";
	
	//PARA PUERTO
	String num_aux=0;
	
	//f_titok_r123123_001
	
	// constructor
	comando (String x, String y) {
		num = x;
		texto = y;
	}
	
	
	//String aux;
	aux = parte1+"nombre_generico"+parte3+"ip_generica"+parte4+mascara_aux+parte5+str_aux+parte6+str_aux+";";

	PromptOK(aux);
};
*/

#endif

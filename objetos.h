#ifndef _L3L4_objetos_h_
#define _L3L4_objetos_h_
#include <iostream>
#include <string>
using namespace std;


/*
-- mi plantilla de objetos

class objeto {
	public:
	//parametros
	int num;
	string texto;
	
	// metodos
	int funcion();
	
	// constructor
	objeto (int x, string y) {
		num = x;
		texto = y;
	}
};
*/




class comando {
	public:
		
	// parametros
	string s_filtername;
	string s_ipEnBruto;
	string s_svrstartport;
	string s_svrendport;
	
	// objetos
	//nombre_filtro obj_nombreFiltro("f_", "tiktok_", "r01156", 0);
	
	// metodos
	string imprimir(){
		string parte1 = "ADD FILTER:FILTERNAME=\"";
		string parte3 = "\",L34PROTTYPE=STRING,L34PROTOCOL=ANY,SVRIPMODE=IP,SVRIP=\"";// más IP
		string parte4 = "\",SVRIPMASKTYPE=LENGTHTYPE,SVRIPMASKLEN=";
		string mascara_aux= func_sacar_mascara(s_ipEnBruto);
		//string parte5 = ",MSSTARTPORT=0,MSENDPORT=65535,SVRSTARTPORT=0,SVRENDPORT=65535;";
		string parte5 = ",MSSTARTPORT=0,MSENDPORT=65535,SVRSTARTPORT=";
		string parte6 = ",SVRENDPORT=";
		return parte1+s_filtername+parte3+func_sacar_ip(s_ipEnBruto)+parte4+mascara_aux+parte5+s_svrstartport+parte6+s_svrendport+";";
	}
	
	// constructor
	comando(string x_filtername, string x_ipEnBruto ,string x_svrstartport, string x_svrendport) {
		s_filtername = x_filtername;
		s_ipEnBruto = x_ipEnBruto;
		s_svrstartport = x_svrstartport;
		s_svrendport = x_svrendport;
	}
};

class comando_bind {
	public:
	//parametros
	string str_filtername;
	string str_flowFilter;
	
	// metodos
	string salida(){
		//ADD FLTBINDFLOWF:FLOWFILTERNAME="fg_whatsapp",FILTERNAME="f_whatsapp_r01170_001";
		//fg_whatsapp         f_whatsapp_r01170_001";
		return "ADD FLTBINDFLOWF:FLOWFILTERNAME=\""+ str_flowFilter +"\",FILTERNAME=\""+ str_filtername + "\";";
	}
	
	// constructor
	comando_bind (string x1, string x2) {
		str_filtername = x1;
		str_flowFilter = x2;
	}
};


class nombre_filtro{
	public:
	
	// parametros
	string pre;
	string nombre;
	string req;
	string num_auto;
	
	// metodos
	string m_imprimir(){
		return pre+nombre+req+"_"+num_auto;
	}
	
	// constructor
	nombre_filtro(string x_pre , string x_nombre, string x_req, string x_num_auto){
		pre = x_pre;
		nombre = x_nombre;
		req = x_req;
		num_auto = x_num_auto;
	}
};
#endif

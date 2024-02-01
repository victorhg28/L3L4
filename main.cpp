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

//constructor
comandos_L3L4::comandos_L3L4()
{
	CtrlLayout(*this, "L3L4");
	btn_1 <<= THISBACK(Click);
}

void comandos_L3L4::Click(){
	
	lecturaArchivoIPs();
	PromptOK("script generado");
	Close();
}


GUI_APP_MAIN{
	comandos_L3L4 programa;
	
	programa.Sizeable();
	programa.Run();
}

void comandos_L3L4::lecturaArchivoIPs(){
	
	//abriendo archivo
	ifstream ifstream_archivo("ips.txt");
	
	//variable para leer lineas
	string str_aux_text;
	
	//contador
	int i_auxNum=0;
	
	//archivo para guardar el resultado del script
	ofstream archivo_resultado("script_generado.txt", std::ios::trunc);
	
	//generando comando
	while (getline (ifstream_archivo, str_aux_text)) {
		i_auxNum++;
		
		//archivo_resultado << comandoCreacionFiltro(creacionNombreDeFiltro(i_auxNum),  (String)(func_sacar_ip(str_aux_text))     ).ToStd();
		archivo_resultado << comandoCreacionFiltro(creacionNombreDeFiltro(i_auxNum), str_aux_text,FormatInteger(gui_puertoStart),FormatInteger(gui_puertoEnd)).ToStd();
		archivo_resultado << "\n";
	}

	// Cerrando archivo de lectura
	ifstream_archivo.close();
	
	// Cerrando archivo de escritura
	archivo_resultado.close();
};

String comandos_L3L4::creacionNombreDeFiltro(int i_tempContador){
	//struct
	nombreFiltro nFiltro;
	
	nFiltro.pre = "f_";
	nFiltro.nombre = (String)gui_nomServ.GetData();
	nFiltro.req = "_r"+FormatInteger(gui_numReq);
	nFiltro.num_auto = (String)func_formatoNumeracion(i_tempContador);
	
	nFiltro.resultado = nFiltro.pre;
	nFiltro.resultado += nFiltro.nombre;
	nFiltro.resultado += nFiltro.req;
	nFiltro.resultado += "_"+nFiltro.num_auto;
	
	return nFiltro.resultado;
};



String comandos_L3L4::comandoCreacionFiltro(String nombre_f,String ipExtraida, String puertoIni, String puertoFin){
	//String s_filtername = nombre_f;
	//String s_ipEnBruto;
	//String s_svrstartport;
	//String s_svrendport;

	//(String)(func_sacar_ip(
	
	String aux = "ADD FILTER:FILTERNAME=\"";
	aux += nombre_f + "\",L34PROTTYPE=STRING,L34PROTOCOL=ANY,SVRIPMODE=IP,SVRIP=\"";
	//aux += "ip_generica";
	aux += func_sacar_ip(ipExtraida.ToStd());
	aux += "\",SVRIPMASKTYPE=LENGTHTYPE,SVRIPMASKLEN=";
	//aux += "mascara_generica";
	aux += func_sacar_mascara(ipExtraida.ToStd());
	//aux += (String)func_sacar_mascara(ipExtraida.ToStd());
	aux += ",MSSTARTPORT=0,MSENDPORT=65535,SVRSTARTPORT=";
	//aux += "*puerto*";
	aux += puertoIni;
	aux += ",SVRENDPORT=";
	//aux += "*puerto*";
	aux += puertoFin;
	aux += ";";
	
	return aux;
}
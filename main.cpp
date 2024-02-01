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
	
	//Creacion nombre de filtro
	
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
	
	//gui_resultado.SetText(nFiltro.resultado);
	//gui_resultado.SetText(comandoCreacionFiltro(nFiltro.resultado));
	
	// creacion de archivo para guardar resultado
	// Create and open a text file
	ofstream archivo_resultado("filename.txt");

	// Write to the file
	//archivo_resultado << "Files can be tricky, but it is fun enough!";
	archivo_resultado << comandoCreacionFiltro(nFiltro.resultado).ToStd();

	// Close the file
	archivo_resultado.close();
	
	
	
	//String
	
	/*
	//lectura de archivo IPs
	
	//abriendo archivo
	ifstream ifstream_archivo("ips.txt");
	
	//variable para leer lineas
	string str_aux_text;
	
	//generando comando
	while (getline (ifstream_archivo, str_aux_text)) {
		//i_auxNum++;
  		
  		comando obj_comando(nFiltro.resultado,str_aux_text,dat1.str_puerto,dat1.str_puerto);
  		obj_comando.imprimir();
  		
  		str_auxNombreFiltro=obj_nombreFiltro.m_imprimir();
  		
		//cout<<func_generandoBindeado(i_auxNum,obj_nombreFiltro.m_imprimir(), dat1.str_flowFilter);
		//cout<<"\n";
	}

	// Cerrando archivo
	ifstream_archivo.close();
	*/
	
	
}


GUI_APP_MAIN{
	comandos_L3L4 programa;
	
	programa.Sizeable();
	programa.Run();
}

String comandos_L3L4::comandoCreacionFiltro(String nombre_f){
	//String s_filtername = nombre_f;
	//String s_ipEnBruto;
	//String s_svrstartport;
	//String s_svrendport;
	
	String aux = "ADD FILTER:FILTERNAME=\"";
	aux += nombre_f + "\",L34PROTTYPE=STRING,L34PROTOCOL=ANY,SVRIPMODE=IP,SVRIP=\"";
	aux += "ip_generica";
	aux += "\",SVRIPMASKTYPE=LENGTHTYPE,SVRIPMASKLEN=";
	aux += "mascara_generica";
	aux += ",MSSTARTPORT=0,MSENDPORT=65535,SVRSTARTPORT=";
	aux += "*puerto*";
	aux += ",SVRENDPORT=";
	aux += "*puerto*";
	aux += ";";
	
	return aux;
}

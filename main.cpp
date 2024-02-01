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
	
	//Creacion nombre de filtro
	
	//f_titok_r123123_001
	
	// creacion de archivo para guardar resultado
	ofstream archivo_resultado;
	archivo_resultado.open("script_generado.txt", std::ios_base::app);
	//archivo_resultado<<"abc";
	archivo_resultado << comandoCreacionFiltro(creacionNombreDeFiltro()).ToStd();
	archivo_resultado << "\n";
	
	
	
	
	// escribiendo en el archiv
	//archivo_resultado << comandoCreacionFiltro(nFiltro.resultado).ToStd();
	//archivo_resultado << comandoCreacionFiltro(creacionNombreDeFiltro()).ToStd();
	
	
	
	
	//(creacionNombreDeFiltro())
	
	
	//apend en lugar de sobreescribir archivo
	
	
	//archivo_resultado << "\n";
	
	// cerrando el archivo
	archivo_resultado.close();
	
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
	
	//generando comando
	while (getline (ifstream_archivo, str_aux_text)) {
		i_auxNum++;
		//PromptOK( "ip numero " + (String)to_string(i_auxNum)   );
		
		
		
  		
  		//comando obj_comando(nFiltro.resultado,str_aux_text,dat1.str_puerto,dat1.str_puerto);
  		//obj_comando.imprimir();
  		
  		//str_auxNombreFiltro=obj_nombreFiltro.m_imprimir();
  		
				//cout<<func_generandoBindeado(i_auxNum,obj_nombreFiltro.m_imprimir(), dat1.str_flowFilter);
				//cout<<"\n";
	}

	// Cerrando archivo
	ifstream_archivo.close();
};

String comandos_L3L4::creacionNombreDeFiltro(){
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
	
	return nFiltro.resultado;
};



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

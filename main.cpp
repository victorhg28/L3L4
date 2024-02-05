# include "L3L4.h"
//# include "objetos.h"
#include <typeinfo>

#define IMAGECLASS L3L4Img
#define  IMAGEFILE <L3L4/imagenes.iml>
#include <Draw/iml.h>


#include <iostream>
#include <fstream>
#include <string>

#ifndef header_funciones
	#define header_funciones
	#include "funciones.h"
#endif

/*
#ifndef header_objetos
	#define header_objetos
	#include "objetos.h"
#endif
*/
using namespace std;

//declaraion funciones
string func_generandoBindeado(string filterName, string str_filterGroup);

//constructor
comandos_L3L4::comandos_L3L4()
{
	Icon(L3L4Img::icono());
	
	//img_archivo.SetImage(L3L4Img::archivoNoCargado());
	archivo_ok.SetImage(L3L4Img::archivo_X());
	//SetImage(L3L4Img::icono());
	//ImageCtrlSetImage
	
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
	
	//programa.Sizeable();
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
	
	archivo_resultado<< "// Filtros ////////////////////////////////////////////////////////";
	archivo_resultado<< "\n";
	
	//generando comando
	while (getline (ifstream_archivo, str_aux_text)) {
		i_auxNum++;
		
		//archivo_resultado << comandoCreacionFiltro(creacionNombreDeFiltro(i_auxNum),  (String)(func_sacar_ip(str_aux_text))     ).ToStd();
		archivo_resultado << comandoCreacionFiltro(creacionNombreDeFiltro(i_auxNum), str_aux_text,FormatInteger(gui_puertoStart),FormatInteger(gui_puertoEnd)).ToStd();
		archivo_resultado << "\n";
	}
	
	///////
	int contador=1;
	
	//archivo_resultado<<"\n-----------------------";
	//archivo_resultado<<"\nBindeado\n";
	//archivo_resultado<<"-----------------------\n";
	archivo_resultado<<"\n\n// Bindeado ////////////////////////////////////////////////////////\n";
	
	
	while(contador < i_auxNum+1){
		//nombre_filtro obj_nombreFiltro("f_", dat1.str_nombreServicio+"_", dat1.str_numReq, func_formatoNumeracion(contador) );
		archivo_resultado<<func_generandoBindeado(creacionNombreDeFiltro(contador).ToStd(), gui_fg.GetData().ToStd());
		archivo_resultado<<"\n";
		//cout<<"\n";
		
		contador++;
	}
	///////

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
	
	String aux = "ADD FILTER:FILTERNAME=\"";
	aux += nombre_f + "\",L34PROTTYPE=STRING,L34PROTOCOL=ANY,SVRIPMODE=IP,SVRIP=\"";
	aux += func_sacar_ip(ipExtraida.ToStd());
	aux += "\",SVRIPMASKTYPE=LENGTHTYPE,SVRIPMASKLEN=";
	aux += func_sacar_mascara(ipExtraida.ToStd());
	aux += ",MSSTARTPORT=0,MSENDPORT=65535,SVRSTARTPORT=";
	aux += puertoIni;
	aux += ",SVRENDPORT=";
	aux += puertoFin;
	aux += ";";
	
	return aux;
}

string func_generandoBindeado(string filterName, string str_filterGroup){
	return "ADD FLTBINDFLOWF:FLOWFILTERNAME=\""+ str_filterGroup +"\",FILTERNAME=\""+ filterName + "\";";
}



////////////////////////////////////////
// Para drag and drop
////////////////////////////////////////

void comandos_L3L4::DragAndDrop(Point p, PasteClip& d)
{
	if(IsDragAndDropSource())
		return;
	if(AcceptFiles(d)) {
		files = GetFiles(d);
		Refresh();
	}
}

void comandos_L3L4::LeftDrag(Point p, dword keyflags)
{
	if(files.GetCount()) {
		VectorMap<String, ClipData> data;
		AppendFiles(data, files);
		DoDragAndDrop(data, Null, DND_COPY);
	}
}




void comandos_L3L4::Paint(Draw &w)
{
	//w.DrawRect(GetSize(),White());
	
	//w.DrawRect(GetSize(),SColorPaper());
	//w.DrawRect(GetSize(),Black());
	
							      //(R,G,B)
	//w.DrawRect(GetSize(),Color(169,222,156));
	//w.DrawRect(GetSize(),Color(117,159,115));
	w.DrawRect(GetSize(),Color(29,21,34));
	
	
	/*
	w.DrawText(2, 2, "None");
	if(files.GetCount()){
		w.DrawText(2, 2 * Draw::GetStdFontCy(), files[0]);
	}
	*/
	//label1.SetText("antes");
	
	if(files.GetCount()){
		//w.DrawText(2, 2 * Draw::GetStdFontCy(), files[0]);
		lbl_archivo.SetText(files[0]);
		//img_archivo.SetImage(L3L4Img::archivoCargado());
		archivo_ok.SetImage(L3L4Img::archivo_OK());
	}else{
		lbl_archivo.SetText("*arrastre y suelte archivo aqui*");
	}
	
	//label1.SetText("despues");
	
}







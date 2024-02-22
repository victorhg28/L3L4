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
string func_generandoRollback(string filterName);

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
	//btn_pruebas <<= THISBACK(click_pruebas);
	
	
	
//	gui_puerto.Get();
	//puerto80
}
/*
void comandos_L3L4::click_pruebas(){
	//PromptOK((String)rutaArchivo);
	
	//Label
	
	//ruta_static.SetText((String)rutaArchivo);
	
	//files[0].ToStd();
	
	//PromptOK((String)files[0]);
	//PromptOK("aqui"+(String)files[0].ToStd());
	
	
	
	
	//ruta_static.GetText();
	
	//lbl_archivo.GetData().ToStd()
	//PromptOK((String)lbl_archivo.GetData());
}
*/

void comandos_L3L4::Click(){
	if(gui_puerto80 || gui_puerto443 || gui_puerto1935){
		
		
		//lbl_archivo.SetText("*arrastre y suelte archivo aqui*");
		
		//lbl_archivo.GetText().ToStd();
		
		if(lbl_archivo.GetText().ToStd()!="*arrastre y suelte archivo aqui*"){
			lecturaArchivoIPs();
			PromptOK("script generado");
			Close();
		}
		else{
			PromptOK("Seleccione un archivo");
		}
	}
	else{
		PromptOK("Seleccione por lo menos un puerto");
	}
	
}

GUI_APP_MAIN{
	comandos_L3L4 programa;
	//programa.Sizeable();
	programa.Run();
}

void comandos_L3L4::lecturaArchivoIPs(){
	
	ifstream ifstream_archivo(files[0]);
		
	//variable para leer lineas
	string str_aux_text;
	
	//contador
	int i_auxNum=1;
	
	//archivo para guardar el resultado del script
	ofstream archivo_resultado("script_generado.txt", std::ios::trunc);
	
	archivo_resultado<< "// Filtros ////////////////////////////////////////////////////////";
	archivo_resultado<< "\n";
	
	
	
	// Generando comandos ////////////////////////////////////////////////////////////////
	while (getline (ifstream_archivo, str_aux_text)) {
		//archivo_resultado << comandoCreacionFiltro(creacionNombreDeFiltro(i_auxNum),  (String)(func_sacar_ip(str_aux_text))     ).ToStd();

		if(gui_puerto80.Get()){
			archivo_resultado << comandoCreacionFiltro(creacionNombreDeFiltro(i_auxNum), str_aux_text,"80", "80").ToStd();
			archivo_resultado << "\n";
			i_auxNum++;
		}
		
		if(gui_puerto443.Get()){
			archivo_resultado << comandoCreacionFiltro(creacionNombreDeFiltro(i_auxNum), str_aux_text,"443", "443").ToStd();
			archivo_resultado << "\n";
			i_auxNum++;
		}
		
		if(gui_puerto1935.Get()){
			archivo_resultado << comandoCreacionFiltro(creacionNombreDeFiltro(i_auxNum), str_aux_text,"1935", "1935").ToStd();
			archivo_resultado << "\n";
			i_auxNum++;
		}
	}
	
	// Generando bindeado ////////////////////////////////////////////////////////////////
	//int contador=1;
	archivo_resultado<<"\n\n// Bindeado ////////////////////////////////////////////////////////\n";
	
	for (int i = 1; i < i_auxNum; i++) {
		//cout << i << "\n";
		archivo_resultado<<func_generandoBindeado(creacionNombreDeFiltro(i).ToStd(), gui_fg.GetData().ToStd());
		archivo_resultado<<"\n";
		//contador++;
	}
	
	
	/*
	while(contador < i_auxNum){
		archivo_resultado<<func_generandoBindeado(creacionNombreDeFiltro(contador).ToStd(), gui_fg.GetData().ToStd());
		archivo_resultado<<"\n";
		contador++;
	}
	*/
	
	
	// Generando rollback ////////////////////////////////////////////////////////////////
	archivo_resultado<<"\n\n// Rollback ////////////////////////////////////////////////////////\n";
	for (int i = 1; i < i_auxNum; i++) {
		//cout << i << "\n";
		archivo_resultado<<func_generandoRollback(creacionNombreDeFiltro(i).ToStd());
		archivo_resultado<<"\n";
		//contador++;
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
	nFiltro.req = "_r"+(String)gui_numReq.GetData();
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

string func_generandoRollback(string filterName){
	return "RMV FILTER:OPMODE=SPECIFIC,FILTERNAME=\""+filterName+"\";";
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
		//DoDragAndDrop(data, Null, DND_COPY);
	}
}




void comandos_L3L4::Paint(Draw &w)
{
	w.DrawRect(GetSize(),Color(29,21,34));
	
	if(files.GetCount()){
		archivo_ok.SetImage(L3L4Img::archivo_OK());
		lbl_archivo.SetText(files[0]);
	}else{
		lbl_archivo.SetText("*arrastre y suelte archivo aqui*");
	}
	
}







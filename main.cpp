#include "L3L4.h"
# include <string>

using namespace std;

comandos_L3L4::comandos_L3L4()
{
	CtrlLayout(*this, "L3L4");
	
	/*
	date1 ^= date2 ^= [=] {
		result = IsNull(date1) || IsNull(date2) ? "" :
		         Format("There is %d day(s) between %` and %`", abs(Date(~date1) - Date(~date2)), ~date1, ~date2);
	};
	*/
	//miTexto.SetData("asdasdass");
	btn_1 <<= THISBACK(Click);
}

void comandos_L3L4::Click(){
	//funcion();
	//string aux;
	
	/*
	string parte1 = "ADD FILTER:FILTERNAME=\"";
	string parte3 = "\",L34PROTTYPE=STRING,L34PROTOCOL=ANY,SVRIPMODE=IP,SVRIP=\"";// más IP
	string parte4 = "\",SVRIPMASKTYPE=LENGTHTYPE,SVRIPMASKLEN=";
	string mascara_aux= func_sacar_mascara(s_ipEnBruto);
	//string parte5 = ",MSSTARTPORT=0,MSENDPORT=65535,SVRSTARTPORT=0,SVRENDPORT=65535;";
	string parte5 = ",MSSTARTPORT=0,MSENDPORT=65535,SVRSTARTPORT=";
	string parte6 = ",SVRENDPORT=";
	cout<<parte1+s_filtername+parte3+func_sacar_ip(s_ipEnBruto)+parte4+mascara_aux+parte5+s_svrstartport+parte6+s_svrendport+";";
	
	*/
	
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
	//aux=parte1+s_filtername+parte3+func_sacar_ip(s_ipEnBruto)+parte4+mascara_aux+parte5+s_svrstartport+parte6+s_svrendport+";";	
	aux = parte1+"nombre_generico"+parte3+"ip_generica"+parte4+mascara_aux+parte5+str_aux+parte6+str_aux+";";

	PromptOK(aux);
	
	//PromptOK((String)gui_puerto.GetData());
	
	/*
	int num;
	string abc;
	num=gui_puerto.GetData();
	abc=to_string(num);
	PromptOK(   (String)abc   );
	*/
	
	/* ESTEEEE!
	int num_aux=gui_puerto.GetData();;
	string str_aux=to_string(num_aux);
	PromptOK(   (String)str_aux   );
	*/
	
	//PromptOK((String)std::to_string(gui_puerto.GetData()));
	
	
	//PromptOK((String)std::to_string(gui_puerto.GetData()));
	//string rare;
	//rare=static_cast<String>(gui_puerto.GetData());
	//PromptOK(  static_cast<String>(gui_puerto.GetData())   );
	
	
	
	
	
	
	
	//PromptOK(to_string(valor));
	
	
	/*
	String cadena;
	cadena=(String)gui_puerto.GetData();
	PromptOK(cadena);
	*/
	
	
	
	
	
	
	
	//PromptOK((String)gui_puerto.GetData());
	
	//PromptOK(gui_puerto.GetInc());
	
	//printf("Your age is %d", 13);
	
	
	//PromptOK(std::to_string(num));

	//aux="adad";
	//PromptOK((String)gui_nomReq.GetData());
	//PromptOK(aux);
}

void comandos_L3L4::funcion()
{
	//PromptOK("generic text");
	PromptOK((String)gui_nomReq.GetData());
	//gui_numReq
}

GUI_APP_MAIN
{
	comandos_L3L4().Run();
}

#ifndef _L3L4_funciones_h_
#define _L3L4_funciones_h_
#include <iostream>
#include <string>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////
// declaración de funciones 
/////////////////////////////////////////////////////////////////////////////////////////////////////
string func_sacar_mascara(string str_ip_con_mascara);
string func_sacar_ip(string str_ip_con_mascara);
string func_formatoNumeracion(int entrada);


/////////////////////////////////////////////////////////////////////////////////////////////////////
// definicion de funciones
/////////////////////////////////////////////////////////////////////////////////////////////////////
string func_sacar_mascara(string str_ip_con_mascara){
	
	size_t found = str_ip_con_mascara.find("/");
	if (found != string::npos){
		return str_ip_con_mascara.substr(found+1);
	}
    return "error en funcion sacar mascara";
}

string func_sacar_ip(string str_ip_con_mascara){
	
	size_t found = str_ip_con_mascara.find("/");
	if (found != string::npos){
		return str_ip_con_mascara.substr(0,found);
	}
    return "error en funcion sacar ip";
}

string func_formatoNumeracion(int entrada){
	
	// formato 000
	if (entrada<10){
		return "00"+to_string(entrada);
		//.size()
	}
	else if (entrada<100){
		return "0"+to_string(entrada);
	}
	else{
		return to_string(entrada);
	}
}


//probando sub strings
//	string hola = "hola/200";
//	size_t found = hola.find("/");
//	if (found != string::npos){
//		cout<<hola.substr(found+1);
//	}
#endif

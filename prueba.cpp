#include <fstream>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <random>
#include <string>
#include <sstream>
#include <vector>
#include <locale>
#include <utility>
#include <map>
#include <fstream>
#include <ios>
#include <iterator>

using namespace std;


/*Estructura de datos para guardar parmetros del nodo*/
struct ContNodo {
	int clasi; // Rango de clasificacion entre 1= linea ; 2 = back 
	int demanda;
	int e;
	float l;
	float s;

	ContNodo(int a, int b, int c, float d, float e);
	ContNodo();
};
struct Vehiculo{
	int capacidad;

	Vehiculo(int a);
	Vehiculo();
};
ContNodo::ContNodo(int a, int b, int c, float d, float e) {

	clasi = a; demanda = b; e = c; l = d; s = e;
}
ContNodo::ContNodo() {
	clasi = 0; demanda = 0; e = 0; l = 0; s = 0;
}

Vehiculo::Vehiculo(int a) {

	capacidad = a;
}
Vehiculo::Vehiculo() {
	capacidad = 0;
}

typedef pair<int, ContNodo> auxStruc;



vector<int> quitarChar(string s) {
	locale loc;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i], loc) == false) {
			s[i] = ' ';
		}
	}
	vector<int> v;
	int aux;
	stringstream daniel(s);
	while (daniel >> aux) {
		v.push_back(aux);
	}
	return v;
}

vector<double> quitar_Char(string s , vector <double> anterior) {
	locale loc;
        int inicio = 0;
        int largo_cadena =0;
        int posDato = 1;
        string dato;
        vector<double> v;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '	') {
                    if(posDato==1||posDato==2||posDato==3){
                    	dato = s.substr(inicio , largo_cadena);
			}
                    switch(posDato){
				case 1:
				 v.push_back(stoi(dato));
				 posDato = posDato +1;
                                 inicio = i+1;
                                 largo_cadena = 0; 
				 break;
				case 2:
				 v.push_back(stoi(dato)); 
                                 posDato = posDato +1; 
                                 inicio = i+1; 
                                 largo_cadena = 0; 
                                 break;
                                case 3:
                                 v.push_back(stod(dato)) ;
                                 posDato = posDato +1; 
                                 inicio = i+1; 
                                 largo_cadena = 0; 
                                 break;
                                case 4:
				 dato = s.substr(inicio);
                                 dato = dato.substr(0,dato.size()-1);
                                 v.push_back(stold(dato));
                                 posDato = posDato +1; 
                                 inicio = i+1; 
                                 largo_cadena = 0;
                                 break; 
 
			}
		}
		largo_cadena = largo_cadena +1;
	}

	return v;
}

void Lectura(string nombre_archivo) {
	ifstream fin;

	string linea;
	string linea_saltada;
	vector<int>::iterator it;
	vector<int> vec;
	vector<double> vec_2;
	vector<float> aux;
	ContNodo nodoaux;
	map<int, ContNodo> Nodo;
	map<int, Vehiculo> Vehiculos;


	if (fin.fail()) {
		cout << "Cannot open text." << endl;
	}
	if (!fin.is_open()) {
		fin.open(nombre_archivo, ios::in);
	}

	while (getline(fin, linea)) {
		if (linea.find("\t") != string::npos) {

			vec = quitarChar(linea);

			break;

		}
	}
	int contador = 0;
        int nodos = vec[0];
        int i = 0;

	while (!fin.eof()) {
		getline(fin,linea_saltada);
		vec_2= quitar_Char(linea_saltada , vec_2);
                if(vec_2.size() > 0){
                        nodoaux.clasi = 0;
        		nodoaux.demanda = vec_2[0];
        		nodoaux.e = vec_2[1];
        		nodoaux.l = vec_2[2];
        		nodoaux.s = vec_2[3];
                	Nodo.insert(auxStruc(contador,nodoaux));
                        contador = contador +1;
                }

	}

	fin.close();

	//int i = 0;
	//int nodos = vec[0];
	int vehiculos = vec[3];
	int tiempo_max = vec[4];

	for (i = 1; i <= vehiculos;i++)
	{

		Vehiculos[i] = Vehiculo(0);
		for (auto it = Vehiculos.begin(); it != Vehiculos.end(); it++) {

			
			it->second.capacidad = vec[4];
			
		}
	}


	cout << "PRINT DE NODOS" << endl;
	
		for (auto it = Nodo.begin(); it != Nodo.end(); it++) {

			if (it->first>=vec[2])
			{
				it->second.clasi = 1;
			}
		}


	for (auto it = Nodo.begin(); it != Nodo.end(); it++) {
		
		cout << it->first << "  "<< it->second.clasi <<"  "<< it->second.demanda <<"  "<< it->second.e <<"  "<< it->second.l <<"  "<< it->second.s << endl;
                
		
	}

	cout << "PRINT DE VEHICULOS" << endl;
	for (auto it = Vehiculos.begin(); it != Vehiculos.end(); it++) {

		cout << it->first << "  " << it->second.capacidad << endl;

	}
	
}







int main()
{
	string nombre_archivo = "/home/raul/Desktop/Input.txt";
	Lectura(nombre_archivo);
}

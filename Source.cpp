#include <fstream>
#include <iostream>
#include<iomanip>
#include <math.h>
#include <random>
#include <string>
#include <sstream>
#include<vector>
#include<locale>
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
	float e;
	float l;
	int s;

	ContNodo(int a, int b, float c, float d, int e);
	ContNodo();
};
struct Vehiculo{
	int capacidad;

	Vehiculo(int a);
	Vehiculo();
};
ContNodo::ContNodo(int a, int b, float c, float d, int e) {

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

map<int, ContNodo> Nodo_1;



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

vector<float> quitar_Char(string s) {
	locale loc;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i], loc) == false) {
			s[i] = ' ';
		}
	}
	vector<float> v;
	int aux;
	stringstream daniel(s);
	while (daniel >> aux) {

		v.push_back(aux);
	}
	return v;
}

void Lectura(string nombre_archivo) {
	ifstream fin;

	string linea;
	string linea_saltada;
	vector<int>::iterator it;
	vector<int> vec;
	vector<float> vec_2;
	vector<float> aux;
	ContNodo nodoaux;
	map<int, ContNodo> Nodo;
	map<int, Vehiculo> Vehiculos;
	//map<int,ContNodo > mapa_aux;

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
	int contador = 1;

	while (!fin.eof()) {
		fin >> linea_saltada;
		vec_2= quitar_Char(linea_saltada);
		//aux[contador] = vec_2[contador];
        nodoaux.clasificacion = 0;
        nodoaux.demanda = vec_2[0];
        nodoaux.e = vec_2[1];
        nodoaux.l = vec_2[2];
        nodoaux.s = vec_2[3];
        Nodo.push_back(contador , nodoaux);
        contador = contador + 1;
		//contador++;
		//aux.clear();
	}
	
	
	//map<int, ContNodo> Nodo;
	//map<int, Vehiculo> Vehiculos;
	int i = 0;
	int nodos = vec[0];
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
	
	for (i = 0; i <nodos;i++)
	{
		
		Nodo[i] = ContNodo(0,0,0,0,0);
		for (auto it = Nodo.begin(); it != Nodo.end(); it++) {

			if (it->first>=vec[1+1])
			{
				it->second.clasi = 1;
			}
		}
	}

	for (auto it = Nodo.begin(); it != Nodo.end(); it++) {
		
		cout << it->first << "  "<< it->second.clasi << endl;
		
	}

	cout << "PRINT DE VEHICULOS" << endl;
	for (auto it = Vehiculos.begin(); it != Vehiculos.end(); it++) {

		cout << it->first << "  " << it->second.capacidad << endl;

	}
	
	fin.close();
}







int main()
{
	string nombre_archivo = "C:\\Users\\Tbusiness\\Source\\Repos\\Entrega2\\Entrega2\\Input.txt";
	Lectura(nombre_archivo);
}
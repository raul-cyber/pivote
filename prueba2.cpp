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
	int s;
	float e;
	float l;

	ContNodo(int a, int b, int c, float d, float e);
	ContNodo();
};
struct Vehiculo {
	int capacidad;

	Vehiculo(int a);
	Vehiculo();
};
ContNodo::ContNodo(int a, int b, int c, float d, float e) {

	clasi = a; demanda = b; s = c; e = d; l = e;
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
vector < vector < int > > matrix;
using Nodo_1 = std:: pair<int, ContNodo>;
map<int, ContNodo> Nodo;



vector<int> quitarChar(string s) {
	locale loc;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i], loc) == false) {
			s[i] = '	';
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

vector<double> quitar_Char(string s, vector <double> anterior) {
	locale loc;
	int inicio = 0;
	int largo_cadena = 0;
	int posDato = 1;
	string dato;
	vector<double> v;
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '	') {
			if (posDato == 1 || posDato == 2 || posDato == 3) {
				dato = s.substr(inicio, largo_cadena);
			}
			switch (posDato) {
			case 1:
				v.push_back(stoi(dato));
				posDato = posDato + 1;
				inicio = i + 1;
				largo_cadena = 0;
				break;
			case 2:
				v.push_back(stoi(dato));
				posDato = posDato + 1;
				inicio = i + 1;
				largo_cadena = 0;
				break;
			case 3:
				v.push_back(stod(dato));
				posDato = posDato + 1;
				inicio = i + 1;
				largo_cadena = 0;
				break;
			case 4:
				dato = s.substr(inicio);
				dato = dato.substr(0, dato.size()-1);
				v.push_back(stold(dato));
				posDato = posDato + 1;
				inicio = i + 1;
				largo_cadena = 0;
				break;

			}
		}
		largo_cadena = largo_cadena + 1;
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
//	map<int, ContNodo> Nodo;
	map<int, Vehiculo> Vehiculos;
	vector < vector <int> > Matriz_Distancia;


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
		getline(fin, linea_saltada);
		vec_2 = quitar_Char(linea_saltada, vec_2);
		cout << vec_2.size() << endl;
		if (vec_2.size() > 0) {
			nodoaux.clasi = 0;
			nodoaux.demanda = vec_2[0];
			nodoaux.s = vec_2[1];
			nodoaux.e = vec_2[2];
			nodoaux.l = vec_2[3];
			Nodo.insert(auxStruc(contador, nodoaux));
			contador = contador + 1;
		}

	}

	fin.close();



	cout << "fin" << endl;

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

		if (it->first >= vec[2])
		{
			it->second.clasi = 1;
		}
	}


	for (auto it = Nodo.begin(); it != Nodo.end(); it++) {


		cout << it->first << " " << it->second.clasi << " " << it->second.demanda << " " << it->second.s << " " << it->second.e << " " << it->second.l << endl;
	}

	cout << "PRINT DE VEHICULOS" << endl;
	for (auto it = Vehiculos.begin(); it != Vehiculos.end(); it++) {

		cout << it->first << "  " << it->second.capacidad << endl;

	}




}


void lectura_distancia(string filename)
{

	
	ifstream fin;
	string linea;
	int cont = 0;
	int nodos = 10;
        vector < vector < int > > pivote;
	vector < vector <int> >::iterator it2_;
	vector <int>::iterator it_;
	Vehiculo vehiaux;

	if (fin.fail()) {
		cout<< "Cannot open text." << endl;
	}
	if (!fin.is_open()) {
		fin.open(filename, ios::in);
	}
	vector <int> aux1;
	while (!fin.eof()) {
		getline(fin, linea);
		for (int i = 0; i < nodos-1; i++)
		{
			for (int j = 0; j < nodos; j++)
			{
				aux1 = quitarChar(linea);


			}

		    if(aux1.size() > 0){ 
		       pivote.push_back(aux1);
			   }

                // matrix.push_back(aux1);

		}
		//Matriz_Distancia.push_back(aux1);

		cont++;
	}
        matrix = pivote;
        cout << "Elementos en matrix "<< matrix.size() << endl;

	cout << "####################################" << endl;
	cout << "######## Info Matriz ###########" << endl;

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << "Dato : " << i << j << endl;
			cout << matrix[i][j] << " ";
		}

		cout << endl;

	}
	//Para ver la distancia total recorrida
	int distancia = 0;
	map<int, ContNodo> Nodo;

	int demanda = 0;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++)
		{
			
			
			if (i <4 && j<4)
			{

				cout << "Entrando" << endl;
				for (auto it = Nodo.begin(); it != Nodo.end(); it++) {

					if (demanda<=30)
					{
						demanda = demanda + it->second.demanda;
						cout << "Demanda en :" << i << " , " << j <<" :"<<demanda << endl;
					}
				}
				distancia = distancia + matrix[i][j];
				cout << "Distancia recorrida en  " << i << j << " :" << distancia << endl;
			}
			}
			
			

		cout << endl;

	}
	

	cout << "fin" << endl;
	fin.close();
}






int main()
{
	string nombre_archivo = "/home/raul/Desktop/Input.txt";
	Lectura(nombre_archivo);
	string filename = "/home/raul/Desktop/Distancia.txt";
	lectura_distancia(filename);
        cout << "Total de datos guardados en el vecto matrix "<< matrix.size() << endl;
        cout << "Cantidad de datos en el nodo lleno: "<< Nodo.size() << endl;
	int distancia = 0;
	int demanda = 0;
        Nodo_1 nodo;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++)
		{


			if (i < 4 && j < 4)
			{
				cout << "Entrando" << endl;

				if (nodo.first == i)
					cout << "Nodo en i> " << i << endl;
					if (demanda <= 30)
					{
						demanda = demanda + nodo.second.demanda;
						cout << "Demanda en :" << i << " , " << j << " :" << demanda << endl;
					}

				distancia = distancia + matrix[i][j];
				cout << "Distancia recorrida en  " << i << j << " :" << distancia << endl;
			}
		}

	}

		cout << endl;

}

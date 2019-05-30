#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

struct metal
{
	string nombre;
	int cantidad;
	float precio;
};
vector<metal>respuesta;

bool acompare(metal ls,metal ls2){
	return ls.precio>ls2.precio;
}
vector<metal>metales;

int main()
{
	int tam;
	int esperado=650;
	ifstream in("metales.txt");
	in>>tam;
	for(int i=0;i<tam;i++){
		metal temp;
		in >> temp.cantidad;
		in >> temp.precio;
		in >> temp.nombre;
		metales.push_back(temp);
	}
	sort(metales.begin(), metales.end(), acompare);
	for(int i=0;i<tam;i++){
		cout << metales[i].cantidad<< " "<< metales[i].precio<<endl;
	}
	for(int i = 0; i < tam; i++){
		if(metales[i].precio > esperado){
			continue;
		}
		int temp = esperado / metales[i].precio;
		metal fin;
		if(temp>metales[i].cantidad){
			esperado = esperado - metales[i].precio * metales[i].cantidad;	
			fin.cantidad=  metales[i].cantidad;
		}
		else{
			esperado = esperado-metales[i].precio*temp;
			fin.cantidad = temp;
		}
		
		fin.precio=metales[i].precio;
		fin.nombre=metales[i].nombre;
		respuesta.push_back(fin);
		if(esperado == 0)
			for(int i = 0; i < respuesta.size(); i++){
				cout<<respuesta[i].nombre<<" vender "<<respuesta[i].cantidad<<" a "<<respuesta[i].precio<<endl;
			}
	}
	return 0;
}

/*   755   */
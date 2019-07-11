/** @file MiniColST.cpp
@author iMawe
@version Revision 1.1
@brief implementacion del un MST-coloreado en C++.
*/

/**
@mainpage
En el siguiente .cpp se demuestra una forma en la que se puede
programar un MST-coloreado para que esta cumpla las mismas 
funciones que el original con la nueva condicional de los colores.

- Haciendo uso de los temas realizados durante el semestre
- Incluyendo una librería de salida y entrada de archivos para graficar.
- Incluyendo la librería algorithm para poder usar las distintas funciones

*/

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <fstream>

using namespace std;

#define MAX 1005

//UnionFind
int Parent[MAX];

//Inicializacion
/** Funcion crear los pares.
 *  @param n, se envia el numero de vertices
 */
void MakeSet(int n){
	for(int i = 1; i <= n; ++i) Parent[i] = i;
}

//Encontrar la raiz del metodo actual
/** Funcion para buscar la raiz.
 *  @param c, se envia el nodo a buscar
 */
int Find(int x){
	return (x == Parent[x]) ? x : Parent[x] = Find(Parent[x]);
}

//Unir dos componentes
/** Funcion para realizar la union.
 *  @param x, y, son los vertices que se van a unir
 */
void Union(int x, int y){
	Parent[Find(x)] =  Find(y);
}

//Verificar ciclo
/** Funcion para verificar si existe un ciclo.
 *  @param x, y, son los vertices los cuales se van a comparar si forman un ciclo.
 */
bool Ciclo(int x, int y){
	if(Find(x) == Find(y)) return true;
	return false;
}

//Fin UnionFind

int V, E; //num Vertices, num Aristas

//Estructura de la arista

/**
 * @struct Edge
 * @brief Representa la estructura de las aristas
 * @detail Contiene los datos miembros de la arista, una funcion para condicionar el sort 
 */

// orig = origen, dest = destino, peso = peso, color = color Azul o Rojo
struct Edge{
	int orig, dest, peso;
	char color;
	bool flag;
	Edge(){}
	//Comparador por peso, me servira al momento de ordenar lo realizara en orden ascendente
    //Cambiar signo a > para obtener el arbol de expansion maxima
    bool operator<(const Edge &e) const {
        return peso < e.peso;
    }

}arista[MAX]; //Arreglo de aristas 
Edge MST[MAX]; //Arreglo de aristas del MST encontrado


/** Funcion para imprimir el grafo.
 *  @param Edge, num, se manda el MST para poder imprimirlo y el numero de aristas que tiene
 */
void printGrafo(Edge MST[], int num){
	string num_arch = to_string(num);
    string ext1 = ".dot";
    string num_xt1=""+ num_arch +""+ ext1 +"";
    ofstream es(num_xt1);
    ////////
    string s = to_string(num);
    string pt1="dot.out.lnk -Tpng  < ";
    string pt2=" > ";
    string pt3=".png";
    string rt=""+ pt1 +""+ num_xt1 +""+ pt2 +""+ s +""+ pt3 +"";
    const char *buffer = rt.c_str();
    ////////
    es<<"digraph mentions {"<<endl;
    for (int i = 0; i < num; i++) {
		if(MST[i].color == 'B'){
			es << "\t edge [color=blue];"<< endl;
			es << MST[i].orig << " -> ";
			es << MST[i].dest << " [label=\"";
			es << MST[i].color <<"\"];" << endl;
		}
		else if(MST[i].color == 'R'){
			es << "\t edge [color=red];"<< endl; 
			es << MST[i].orig << " -> ";
			es << MST[i].dest << " [label=\"";
			es << MST[i].color <<"\"];" << endl;
		}
	}
    es<<"}"<<endl;
    es.close();
    system(buffer);

	//system("dot -Tpng MST.dot -o MST.png");
	//system("nohup display MST.png &" );
}

/** Funcion para imprimir el grafo.
 *  @param Edge, num, se manda el MST para poder imprimirlo y el numero de aristas que tiene
 */
void printG(Edge MST[], int num){
	string num_arch = to_string(num);
    string ext1 = ".dot";
    string num_xt1=""+ num_arch +""+ ext1 +"";
    ofstream es(num_xt1);
    ////////
    string s = to_string(num);
    string pt1="dot.out.lnk -Tpng  < ";
    string pt2=" > ";
    string pt3=".png";
    string rt=""+ pt1 +""+ num_xt1 +""+ pt2 +""+ s +""+ pt3 +"";
    const char *buffer = rt.c_str();
    ////////
    es<<"digraph mentions {"<<endl;
    for (int i = 0; i < num; i++) {
		if(MST[i].color == 'B'){
			es << "\t edge [color=blue];"<< endl;
			es << MST[i].orig << " -> ";
			es << MST[i].dest << " [label=\"";
			es << MST[i].peso <<"\"];" << endl;
		}
		else if(MST[i].color == 'R'){
			es << "\t edge [color=red];"<< endl; 
			es << MST[i].orig << " -> ";
			es << MST[i].dest << " [label=\"";
			es << MST[i].peso <<"\"];" << endl;
		}
	}
    es<<"}"<<endl;
    es.close();
    system(buffer);

	//system("dot -Tpng MST.dot -o MST.png");
	//system("nohup display MST.png &" );
}

/** Funcion para hallar MST con k aristas azules.
 *  @param n, el numero de aristas que tiene el MST
 */
void AristasAzulesK(int n){
	int orig, dest, peso;
	char color;
	int total = 0; //Peso total del MST
	int numAristas = 0; //Numero de Aristas del MST
	int cont = n; //Contador de N aristas azules

	MakeSet(V); //Inicializamos cada componente
	sort(arista, arista + E); //Ordenamos las aristas por su comparador

	for(int i = 0; i < E; i++){ //Recorremos las aristas ya ordenadas por peso
		orig = arista[i].orig; //Vértice origen de la arista actual
		dest = arista[i].dest; //Vértice destino de la arista actual
		peso = arista[i].peso; //Peso de la arista actual
	

		//Verificamos si estan o no en la misma componente conexa
		if(!Ciclo(orig, dest)){ //Evito ciclos
			if(arista[i].color == 'B' && cont != 0){
				total += peso; //Incremento el peso total del MST
				MST[numAristas++] = arista[i]; //Agrego al MST la arista actual
				Union(orig, dest); //Union de ambas componentes en una sola
				arista[i].flag = true;
				cont--;
				//cout<< "contador valor -> "<< cont<<endl;
			}
			
		}
	}
	for(int i = 0; i < E; i++){ //Recorremos las aristas ya ordenadas por peso
		orig = arista[i].orig; //Vértice origen de la arista actual
		dest = arista[i].dest; //Vértice destino de la arista actual
		peso = arista[i].peso; //Peso de la arista actual
	
		if(arista[i].flag == false){
			//Verificamos si estan o no en la misma componente conexa
			if(!Ciclo(orig, dest)){ //Evito ciclos
				if(arista[i].color == 'R'){
					total += peso;
					MST[numAristas++] = arista[i]; //Agrego al MST la arista actual
					Union(orig, dest); //Union de ambas componentes en una sola
				}
			}
		}
	}


	//Si el MST encontrado no posee todos los vértices mostramos mensaje de error
    //Para saber si contiene o no todos los vértices basta con que el numero
	//de aristas sea igual al numero de vertices - 1
	if(V - 1 != numAristas){
		puts("No existe MST valido para el grafo ingresado, el grafo debe ser conexo.");
		return;
	}
	if(cont != 1){
		puts("-----El MST encontrado contiene las siguientes aristas-----");
		for(int i = 0; i < numAristas; i++)
			printf("(%d , %d) : %d -> %c\n", MST[i].orig, MST[i].dest, MST[i].peso, MST[i].color); //( vertice u , vertice v ) : peso


		printf("El costo minimo de todas las aristas del MST es : %d\n", total);

		printG(MST, numAristas);
	}
	else{
		puts("No existen aristas suficientes para el MST.");
		return;
	}
}

/** Funcion para hallar MST con el numero maximo aristas azules.
*/
void MaxAristasAzules(){
	int orig, dest;
	char color;
	int numAristas = 0; //Numero de Aristas del MST

	MakeSet(V); //Inicializamos cada componente


	for(int i = 0; i < E; i++){ //Recorremos las aristas ya ordenadas por peso
		orig = arista[i].orig; //Vértice origen de la arista actual
		dest = arista[i].dest; //Vértice destino de la arista actual

		//Verificamos si estan o no en la misma componente conexa
		if(!Ciclo(orig, dest)){ //Evito ciclos
			if(arista[i].color == 'B'){
				MST[numAristas++] = arista[i]; //Agrego al MST la arista actual
				Union(orig, dest); //Union de ambas componentes en una sola
				arista[i].flag = true;
			}
		}
	}

	for(int i = 0; i < E; i++){ //Recorremos las aristas ya ordenadas por peso
		orig = arista[i].orig; //Vértice origen de la arista actual
		dest = arista[i].dest; //Vértice destino de la arista actual
	
		if(arista[i].flag == false){
			//Verificamos si estan o no en la misma componente conexa
			if(!Ciclo(orig, dest)){ //Evito ciclos
				if(arista[i].color == 'R'){
					MST[numAristas++] = arista[i]; //Agrego al MST la arista actual
					Union(orig, dest); //Union de ambas componentes en una sola
				}
			}
		}
	}

	//Si el MST encontrado no posee todos los vértices mostramos mensaje de error
    //Para saber si contiene o no todos los vértices basta con que el numero
	//de aristas sea igual al numero de vertices - 1
	if(V - 1 != numAristas){
		puts("No existe MST valido para el grafo ingresado, el grafo debe ser conexo.");
		return;
	}

	puts("-----El MST encontrado contiene las siguientes aristas-----");
	for(int i = 0; i < numAristas; i++)
		printf("(%d , %d) : %c\n", MST[i].orig, MST[i].dest, MST[i].color); //( vertice u , vertice v ) : color

	printGrafo(MST, numAristas);

}

/** Funcion para hallar MST con el numero minimo aristas azules.
*/
void MinAristasAzules(){
	int orig, dest;
	char color;
	int numAristas = 0; //Numero de Aristas del MST

	MakeSet(V); //Inicializamos cada componente


	for(int i = 0; i < E; i++){ //Recorremos las aristas ya ordenadas por peso
		orig = arista[i].orig; //Vértice origen de la arista actual
		dest = arista[i].dest; //Vértice destino de la arista actual
		color = arista[i].color; //Peso de la arista actual

		//Verificamos si estan o no en la misma componente conexa
		if(!Ciclo(orig, dest)){ //Evito ciclos
			if(arista[i].color == 'R'){
				MST[numAristas++] = arista[i]; //Agrego al MST la arista actual
				Union(orig, dest); //Union de ambas componentes en una sola
				arista[i].flag = true;
			}
		}
	}

	for(int i = 0; i < E; i++){ //Recorremos las aristas ya ordenadas por peso
		orig = arista[i].orig; //Vértice origen de la arista actual
		dest = arista[i].dest; //Vértice destino de la arista actual
		color = arista[i].color; //Peso de la arista actual
	
		if(arista[i].flag == false){
			//Verificamos si estan o no en la misma componente conexa
			if(!Ciclo(orig, dest)){ //Evito ciclos
				if(arista[i].color == 'B'){
					MST[numAristas++] = arista[i]; //Agrego al MST la arista actual
					Union(orig, dest); //Union de ambas componentes en una sola
				}
			}
		}
	}

	//Si el MST encontrado no posee todos los vértices mostramos mensaje de error
    //Para saber si contiene o no todos los vértices basta con que el numero
	//de aristas sea igual al numero de vertices - 1
	if(V - 1 != numAristas){
		puts("No existe MST valido para el grafo ingresado, el grafo debe ser conexo.");
		return;
	}

	puts("-----El MST encontrado contiene las siguientes aristas-----");
	for(int i = 0; i < numAristas; i++)
		printf("(%d , %d) : %c\n", MST[i].orig, MST[i].dest, MST[i].color); //( vertice u , vertice v ) : color

	printGrafo(MST, numAristas);
}

/** Funcion para llamar a MST segun k aristas azules.
*/
void AristasAzules(){
	int num;
	cout<< "Introduzca el numero de aristas azules para el MST"<< endl;
	cin>> num;
	//Realizamos el ingreso del grafo, almacenando las aristas en un arreglo con los datos respectivos
	cout<< "Introduzca el grafo con el formato Origen Destino Peso Color"<< endl;
	for( int i = 0 ; i < E ; ++i )
        scanf("%d %d %d %c", &arista[i].orig, &arista[i].dest, &arista[i].peso, &arista[i].color);

	AristasAzulesK(num);
}

/** Funcion para llamar al MST de Max y Min aristas azules.
*/
void MaxMinAristasAzules(int select){
	cout<< "Introduzca el grafo con el formato Origen Destino Color"<< endl;
	for( int i = 0 ; i < E ; ++i ){
        scanf("%d %d %c", &arista[i].orig, &arista[i].dest , &arista[i].color);
        arista[i].flag = false;
	}
	if(select == 1)
		MaxAristasAzules();
	if(select == 2)
		MinAristasAzules();
}

/** Funcion para iniciar el programa para realizar el MST-Coloreado.
*/
void init(){
	
	cout<< "Ingrese Vertices y Aristas"<< endl;
	scanf("%d %d" , &V , &E );
	cout<< "B = azul,  R = rojo"<< endl;
	cout<< endl;
	int opcion = 0;
	cout<< "¿Que es lo que desea hacer?"<< endl;
	cout<< "1. MST con k aristas azules."<< endl;
	cout<< "2. Arbol de expansion con el minimo numero de aristas azules."<< endl;
	cout<< "3. Arbol de expansion con el maximo numero de aristas azules."<< endl;
	cout<< "4. Exit."<< endl;
	cin>> opcion;
	
	switch(opcion) //donde opción es la variable a comparar
	{
	    case 1: AristasAzules(); //Bloque de instrucciones 1;
	    break;
	    case 2: MaxMinAristasAzules(2); //Bloque de instrucciones 2;
	    break;
	    case 3: MaxMinAristasAzules(1); //Bloque de instrucciones 3;
	    break;
	    case 4: //Bloque de instrucciones 4;
	    break;
	    //Nótese que valor 1 2 y 3 son los valores que puede tomar la opción
	    //la instrucción break es necesaria, para no ejecutar todos los casos.
	    default: cout<< "Opcion incorrecta"<< endl;//Bloque de instrucciones por defecto;
	    //default, es el bloque que se ejecuta en caso de que no se de ningún caso
	}
}


/** Funcion Main.
*/
int main(){
	init();

	/*int q,w;
	char co;

	char b[6][6];

	for(int i = 0; i < 6; ++i){
		for(int j = 0; j < 6; ++j){
	        b[i][j] = '0';
	    }
	}

	for(int i = 0 ; i < E ; ++i){
        cout<< "Arista - > ";
        cin>> q>> w;
        cout<< "Color - > ";
        cin>> co;
        b[q][w] = co;
	}

	for(int i = 0; i < 6; ++i){
		for(int j = 0; j < 6; ++j){
	        cout<< b[i][j];
	    }
	    cout<< endl;
	}
*/

//	MinEST(b, E, V);
	//MaxEST();

	return 0;
}
/*
doxygen -g sample_text.conf

doxygen sample_text.conf

cd html

google-chrome index.html
*/
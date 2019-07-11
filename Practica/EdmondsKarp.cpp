#include<queue>
#include<cstring>
#include<vector>
#include<iostream>

#define MAX 60
#define INF 2147483646

using namespace std; 

// representa las capacidades de las aristas
int Capa[MAX][MAX];

// muestra el flujo que ha pasado a traves de las aristas
int Flujo[MAX][MAX];

// representa la grafica ¡La grafica tambien debe contener los bordes negativos!
vector< int> G[MAX];

// muestra los padres de los nodos de la ruta construida por el BFS
int Parents[MAX];

// muestra el flujo maximo a un nodo en la ruta creada por BFS
int SigCap[MAX];

int bfs(int ini, int fin){
   memset(Parents, -1, sizeof(Parents));
   memset(SigCap, 0, sizeof(SigCap));
   /*for(int i = 0; i < 6; i++){
      cout<< "Parents: "<< Parents[i]<< endl;
      cout<< "SigCap: "<< SigCap[i]<< endl;
   }*/
   queue< int> q;
   q.push(ini);
   Parents[ini] = -2;//inicializa el nodo
   SigCap[ini] = INF;//inicializar el nodo de la ruta actual

   while(!q.empty()){//si q no esta vacio
      int sig = q.front();
      q.pop();
      for(int i = 0; i < G[sig].size(); i++){
         int aux = G[sig][i];
         cout<< "aux -> "<< aux<< endl;
         if(Parents[aux] == -1){
            if(Capa[sig][aux] - Flujo[sig][aux] > 0){
               //actualizamos el padre del futuro nodo para que sea el nodo actual
               Parents[aux] = sig;
               //verificamos cual es la capacidad de borde residual minima hasta el momento
               SigCap[aux] = min(SigCap[sig], Capa[sig][aux] - Flujo[sig][aux]);
               //si hemos llegado al nodo final, los bfs deberían terminar
               if(aux == fin){
                  for(int i = 0; i < 6; i++){
                     cout<< "Parents: "<< Parents[i]<< endl;
                     cout<< "SigCap: "<< SigCap[i]<< endl;
                  }
                  return SigCap[fin];
               }
               //anadimos nuestro futuro nodo a la cola
               q.push(aux);
            }
         }
      }
   }
   return 0;
}

int EK(int ini, int fin){
   int maxFlow = 0;
   while(true){
      // encontramos un camino aumentado y el flujo maximo correspondiente
      int flow = bfs(ini, fin);
      cout<< flow<<endl;
      // si no podemos encontrar mas caminos, el flujo sera 0
      if(flow == 0) break;
      maxFlow += flow;
      int sig = fin;
      // actualizamos la matriz de flujo pasada
      while(sig != ini){
         int ant = Parents[sig];
         cout<< "anterior -> "<< Parents[sig]<< endl;
         Flujo[ant][sig] += flow;
         Flujo[sig][ant] -= flow;
         sig = ant;
      }
   }
   return maxFlow;
}

int main(){
   int nodes, edges;
   cout<< "ingrese el numero de nodos y aristas"<< endl;
   cin>> nodes>> edges;

   int s, d;
   cout<< "entrar en la inicio y fin"<< endl;
   cin>> s>> d;

   for(int i = 0; i < edges; i++){
      cout<<"ingrese el vertice inicial y final junto con la capacidad"<< endl;
      int a, b, capacity;
      cin>> a>> b>> capacity;

      Capa[a][b] = capacity;
      G[a].push_back(b);

      //anadiendo el borde negativo
      G[b].push_back(a);
   }
   int maxFlow = EK(s, d);

   cout<< maxFlow<< endl;


   for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
         cout<< Flujo[i][j]<< " ";
      }
      cout<< endl;
   }
   return 0;
}


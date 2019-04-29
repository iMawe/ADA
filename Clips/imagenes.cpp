#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std; 
# define INF 999999999 

int tam;

struct Scene{
  vector< string> w;
  vector< int> interes;
  char type;
  int nump;
  bool free;
  Scene(){
    for(int j = 0; j < tam; j++) interes.push_back(0);
    free = 1;
  }
  bool Exist(string sc1){
    for(int i = 0; i < w.size(); i++){
      if(sc1 == w[i]){
        return  1;
      }
    }
    return 0;
  }
  void Print(){
    for(int i  =0; i < interes.size(); i++) cout<< " "<< interes[i]<< " ";
    cout<< endl;
  }
  void ShowP(){
    if(free == 0) return;
    for(int i = 0; i < w.size(); i++) cout<< " "<< w[i]<< " ";
    cout<< endl;
  }
};

class Graph{
private:
  int V;
  list< pair< int, int>> *gra;
public: 
  Graph(int V){ 
    this->V = V; 
    gra = new list< pair< int, int>> [V]; 
  }
  void AddEdge(int u, int v, int w){
    gra[u].push_back(make_pair(v, w)); 
    gra[v].push_back(make_pair(u, w));
  }
  void Prim(){
    priority_queue< pair< int, int>, vector < pair< int, int>> , greater< pair< int, int>>> pq; 
    int aux = 0;
    vector< int> key(V, INF); vector< int> parent(V, -1); vector< bool> VP(V, false); 
    pq.push(make_pair(0, aux)); 
    key[aux] = 0; 
    while (!pq.empty()){ 
      int u = pq.top().second; 
      pq.pop(); 
      VP[u] = true;
      list< pair< int, int>>::iterator i; 
      for (i = gra[u].begin(); i != gra[u].end(); ++i){ 
        int v = (*i).first; 
        int weight = (*i).second; 
        if (VP[v] == false && key[v] > weight){ 
          key[v] = weight;
          pq.push(make_pair(key[v], v)); 
          parent[v] = u; 
        } 
      } 
    } 
    bool visited[V];
    for (int i = 1; i < V; ++i){
      if (visited[parent[i]] != 1) printf("%d -- %d\n", parent[i], i);
      else cout<<i<<endl;
      visited[parent[i]] = 1;
    }       
  } 
};


vector< Scene> sc1;

int main(){
  int tam1;
  string string;
  char type;
  ifstream in("a_example.txt");
  in>> tam;
  Graph gra(tam);
  int aux = 0;
  for(int i = 0; i < tam; i++){
    Scene sc2;
    in>> type;
    sc2.type = type;
    in>> tam1;
    sc2.nump = tam1;
    for(int j = 0; j < tam1; j++){   
      in>> string;
      sc2.w.push_back(string);
    }
    sc1.push_back(sc2);
    if(type == 'V' && aux == 0) aux = 1;
    else if(type == 'V' && aux == 1){
      int cant = sc1[i].w.size();
      for (int k = 0; k < cant ; k++){
        if(sc1[i].Exist(sc1[i].w[k])) continue;
        sc1[i].w.push_back(sc1[i].w[k]);
        cout<<sc1[i].w[k]<< endl;
      }
      sc1[i].type = 'H';
      sc1[i].free = 0;
      aux = 0;
    }
  }
   for(int i = 0; i < sc1.size() - 1; i++){
    for(int j = 0; j < sc1[i].nump; j++){
      for(int k = i + 1;k < sc1.size(); k++){
        if(sc1[k].free and sc1[k].type!='V') if(sc1[k].Exist(sc1[i].w[j])) sc1[i].interes[k]++;
      }
      for(int k = i +1 ; k < sc1.size(); k++){
        int aux = sc1[i].nump - sc1[i].interes[k], 
        aux2 = sc1[k].nump - sc1[i].interes[k],
        inter = sc1[i].interes[k],
        aux3 = min(aux,aux2);
        aux3 = min(inter, aux3);
        gra.AddEdge(i,k,-aux3);
        sc1[i].interes[k] = aux3;
      }
    }
  }
  for(int i = 0; i < sc1.size(); i++) sc1[i].ShowP();
  //for(int i = 0; i < sc1.size(); i++) sc1[i].Print();
  gra.Prim();
  return 0;

}

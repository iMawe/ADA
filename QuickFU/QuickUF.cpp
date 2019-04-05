#include <iostream>
#include <vector>
using namespace std;

int size = 10;

void quickfind(int a, int b){
  int aux1 = A[a];
  int aux2 = A[b];
  for(int i = 0; i < size; i++){
    if(aux1 == A[i])
      A[i] = aux2;
  }
}

void quickunion(int a, int b){
  while(a != A[a]) int aux1 = A[a];
  while(b != A[b]) int aux2 = A[b];
  A[aux1] = aux2;
}

void quickunionran(int a, int b){
  while(a != A[a]) int aux1 = A[a];
  while(b != A[b]) int aux2 = A[b];

  if (B[aux1] < B[aux2]){
    A[aux1] = aux2;
    B[aux2] += B[aux1];
  }
  else if (B[aux1] < B[aux2]){
    A[aux2] = aux1;
    B[aux1] += B[aux2];
  }
  else{
    A[aux1] = aux2;
    B[aux2] += B[aux1];
  }
}

/*
void printARBOL(int num){
    string num_arch = to_string(num);
    string ext1 = ".dot";
    string num_xt1=""+ num_arch +""+ ext1 +"";
    ofstream es(num_xt1);
    ////////
    string s = to_string(num);
    string pt1="dot.lnk -Tpng  < ";
    string pt2=" > ";
    string pt3=".png";
    string rt=""+ pt1 +""+ num_xt1 +""+ pt2 +""+ s +""+ pt3 +"";
    const char *buffer = rt.c_str();
    ////////
    es<<"digraph mentions {"<<endl;
    printARBOL(es,root);
    printCOLOR(es,root);
    es<<"}"<<endl;
    es.close();
    system(buffer);
}


void printARBOL(ofstream & es,node<K,D> *n){
    if(n!=NULL){
        if(n->p_child[0]!=NULL){
            es<<n->key;
            es<<" -> ";
            es<<n->p_child[0]->key<<endl;
            printARBOL(es,n->p_child[0]);
        }
        if(n->p_child[1]!=NULL){
            es<<n->key;
            es<<" -> ";
            es<<n->p_child[1]->key<<endl;
            printARBOL(es,n->p_child[1]);
        }
    }
}
*/

int main(){
  vector<int> A;
  vector<int> B;
  for(int i = 0; i < size; i++){
    A.push_back(i);
    B.push_back(1);
  }
  quickfind(1, 4);
  quickfind(4, 3);
  quickfind(6, 7);
  quickfind(8, 1);
  quickfind(3, 1);
  quickfind(7, 0);
  quickfind(7, 3);
  quickfind(6, 1);
  for(int i = 0; i < size; i++)
    cout<< A[i]<< " ";
  cout<< endl;
  A.clear();
  B.clear();
  inicio();
  quickunion(1, 4);
  quickunion(4, 3);
  quickunion(6, 7);
  quickunion(8, 1);
  quickunion(3, 1);
  quickunion(7, 0);
  quickunion(7, 3);
  quickunion(6, 1);
  for(int i=0;i<size;i++)
    cout<< A[i]<< " ";
  cout<<endl;
  A.clear();
  B.clear();
  inicio();
  quickunionran(1, 4);
  quickunionran(4, 3);
  quickunionran(6, 7);
  quickunionran(8, 1);
  quickunionran(3, 1);
  quickunionran(7, 0);
  quickunionran(7, 3);
  quickunionran(6, 1);
  for(int i = 0; i < size; i++)
    cout<< A[i]<< " ";
  cout<<endl;
}
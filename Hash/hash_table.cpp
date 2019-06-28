#include<iostream>
#include <list>
#include <time.h>
#include <cstdlib>
using namespace std;
#define primo 997
class Hash
{
	list<int> *table;
  float tam;
public:
	Hash(){
    tam=0;
    table = new list<int>[primo];
  }
	void insert(int x){

    int index = hash_function(x);
    if(table[index].size()==0){
      tam++;
    }
    table[index].push_back(x);
  }
	int hash_function(int x) {
		return (x % primo);
	}

	void print(){
    for (int i = 0; i < primo; i++) {
      cout << i;
      for (auto x : table[i])
        cout << " --> " << x;
      cout << endl;
    }
  }
  void tabla(){
    int n=1;
    srand (time(NULL));
    while(1){
      for(int i=0;i<n;i++){
        Hash h;
        int j=rand()%100;
        h.insert(j);
      }
      cout<<"la probabilidad al insertar "<<n<<" elementos es "<<float(tam/primo)<<endl;
      n+=50;
      if(n>primo){
        break;
      }
    }
  }
};
int main()
{
  Hash h;
  h.tabla();

  return 0;
} 

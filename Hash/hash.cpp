#include <bits/stdc++.h>
#include <time.h>
#include <cstdlib>
using namespace std;

#define tam 997

#define primo 7

class double_hash{
private:
    int *list;
    int tam_act;

public:
    double_hash(){
        list = new int[tam];
        tam_act = 0;
        for (int i=0; i<tam; i++)
            list[i] = -1;
    }

    int funtion_hash1(int key){
        return (key % tam);
    }

    int funtion_hash2(int key){
        return (primo - (key % primo));
    }

    void insertHash(int key){
        if (tam_act == tam)
            return;
        int index = funtion_hash1(key);
        if (list[index] != -1){
            int index2 = funtion_hash2(key);
            int i = 1;
            while (1)
            {
            	
                int newIndex = (index + i * index2) % tam;
                if (list[newIndex] == -1)
                {
                    list[newIndex] = key;
                    break;
                }
                i++;
            }
        }
        else
            list[index] = key;
        tam_act++;
    }
    void print(){
        for (int i = 0; i < tam; i++){
            if (list[i] != -1)
                cout << i << " --> "<< list[i] << endl;
            else
                cout << i << endl;
        }
    }
    bool search(int dato,int &id){
        int index = funtion_hash1(dato);
        if (list[index] != dato){
            int index2 = funtion_hash2(dato);
            int i = 1;
            while (1){
                int newIndex = (index + i * index2) % tam;
                if (list[newIndex] == dato){
                	id=newIndex;
                    return 1;
                }
                i++;
            }
            return 0;
        }
        else{
            return 1;
        	id=index;
		}
        
	}
};

int main(){
    double_hash h;
    srand (time(NULL));
    int j;
    for (int i = 0; i < tam; i++){
    	j=rand()%tam;
        h.insertHash(j);
	}

	int i;
	h.print();
	cout<<"dato"<<j<<endl;
	cout<<h.search(j,i)<<endl;
	cout<<"index"<<i<<endl;
	
   
    return 0;
} 

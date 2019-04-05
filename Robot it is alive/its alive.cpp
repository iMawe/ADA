#include <iostream>
#include <time.h>   
#include <stdio.h> 
#include <stdlib.h> 

using namespace std;

int size1 = 10;
int size2 = 10;
int A[size1][size2];


bool Comprobar(int i,int j){
    A[i][j] = 2;
    if (i == size1-1)	return 1;
    if(A[i + 1][j] == 1 and i + 1 < size1){
    	if(Comprobar(i + 1,j))
    		return 1;
    }
    if(A[i - 1][j] == 1 and i - 1 >= 0){
    	if(Comprobar(i - 1, j))
    		return 1;
    }
    if(A[i][j + 1] == 1 and j + 1 < size2){
    	if(Comprobar(i, j + 1))
    		return 1;
    }
    if(A[i][j - 1] == 1 and j - 1 >= 0){
    	if(Comprobar(i,j - 1))
    		return 1;
    }
    
    if(i != size1) return 0;
}

int main(){
  int iSecret;
  srand (time(NULL));
  for(int i = 0; i < size1; i++){
    for (int j = 0; j < size2; j++){
        iSecret = rand() % 2 + 0;
        A[i][j] = iSecret;
        cout<< iSecret<< " ";
    }
    cout<<endl;
  }
  cout<<endl;

  bool c = 0;
	for(int i = 0; i < size2; i++){
		if(A[0][i] == 1){
			if (Comprobar(0, i)){
				cout<< "vive"<< endl;
        c = 1;
				break;
			}
		}
	}
  if (!c) cout<< "muere"<< endl;

	return 0;
}
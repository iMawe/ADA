#include <iostream>
#include <time.h>   
#include <stdio.h> 
#include <algorithm>
#include <vector>
#include <stdlib.h>     /* srand, rand */

using namespace std;

int sum(){
  int c = 0;
  for(int i = 0; i < A.size() - 2; i++){
    for(int j = i + 1; j < A.size() - 1; j++){
      for(int k = j + 1; k < A.size(); k++){
        if(A[i] + A[j] + A[k] == 0)
          c++;
      }
    }
  }
  return c;
}


int sumQS(){
  sort (A.begin(), A.end());
  int c = 0;
  for(int i = 0; i < A.size(); i++){
    for(int j = i + 1; j < A.size(); j++){
      int l = j + 1;
      int r = A.size() - 1;
      int aux1 = -(A[i] + A[j]);
      while (l <= r) { 
        int aux2 = (l + r) / 2; 
        if (A[aux2] == aux1) {
          if(A[j] == aux1){
            aux2 = j + 1;
            for(int k = aux2; k < A.size(); k++){
              if(A[k] != aux1)
                break;
              c++;
            }
          }
          else{
            while(true){
              if(aux1 != A[aux2]){
                aux2++;
                break;
              }
              aux2--;
            }
            for(int k = aux2; k < A.size(); k++){
              if(A[k] != aux1)
                break;
              c++;
            }
          }
          break; 
        }  
        else if (A[aux2] < aux1) 
              l = aux2 + 1; 
        else
              r = aux2 - 1; 
      }
    }
  }
  return c;
}

int main(){
	unsigned int size = 7;

	vector<int> A; //= {-1, -1, -1, 0, 1, 1, 1}
	int iSecret;
	srand (time(NULL));
	for(int i = 0; i < size; i++){
	   	iSecret = rand() % 100 + (-50);
	   	A.push_back(iSecret);
	}
  if (size < 10000){
  	clock_t t;
  	t = clock();
  	cout<< sum()<< endl;
  	t = clock() - t;
  	printf("%f",((float)t)/CLOCKS_PER_SEC);
	}

	clock_t p;
	p = clock();
	cout<< sumQS()<< endl;
	p = clock() - p;
	printf("%f",((float)p)/CLOCKS_PER_SEC);
}
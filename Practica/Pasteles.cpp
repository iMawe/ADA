#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
	vector< pair<int, int>> M;
	int N, k, v, h, aux, aux1, aux2;
	int A[10];

	cin>> N>> k; 
	for(int i = 0; i < N; i++){
		cin>> v>> h;
		aux = max(v, h);
		if(aux != v) M.push_back( make_pair(aux, v));
		else M.push_back( make_pair(aux, h));

	}

	sort(M.begin(), M.end());
	reverse(M.begin(), M.end());
	
	for(int i = 0; i < k; i++){
		A[i] = M[i].first;
	}
	
	for(int i = 0; i < k; i++){
		cout<< "se corta el pastel --> "<< i + 1<< " por el lado: "<< A[i]<<endl;
		aux1 = A[i] * 2;
		aux2 += aux1;
	}
	cout<< "cantidad maxima de crema = "<< aux2;

	return 0;
}
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <stdlib.h>

using namespace std;

int main(){
	vector< pair < int, string> > M;
	vector< pair< int, string> > N;
	int aux = 0;

	string A[] = {"P1", "P2", "P3", "P4", "P5", "P6", "P7", "P8", "P9", "P10"};
	int B[] = {2, 4, 7, 9, 2, 13, 23, 1, 5, 20};

	int n = sizeof(A)/ sizeof(A[0]);

	for (int i = 0; i < n; i++) M.push_back( make_pair(B[i], A[i]) );

	sort(M.begin(), M.end()	);

	for(int i = 0; i < M.size(); i++){
		aux = aux + M[i].first;
		M[i].first = aux;
	}

	for(int i = 0; i < M.size(); i++){
		
		cout << M[i].second << ", " << M[i].first << endl;
	}

	

	return 0;
}
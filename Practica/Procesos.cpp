#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <stdlib.h>

using namespace std;

int main(){
	vector< pair < int, string> > M;

	string A[] = {"P1", "P2", "P3", "P4", "P5", "P6", "P7", "P8", "P9", "P10"};
	int B[] = {2, 4, 7, 9, 2, 13, 23, 1, 5, 20};

	int n = sizeof(A)/ sizeof(A[0]);

	for (int i = 0; i < n; i++) M.push_back( make_pair(B[i], A[i]) );

	sort(M.begin(), M.end()	);

	for(int i = 0; i < M.size(); i++){
		
		cout << M[i].first << ", " << M[i].second << endl;
	}

	

	return 0;
}
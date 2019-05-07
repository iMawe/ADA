#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <stdlib.h>

using namespace std;


int main(){
	vector< pair< int, int>> M;
	int a;
	int aux = 0, aux1 = 0;

	string A[] = {"Indio", "Plata", "Renio", "Paladio", "Osmio", "Iridio", "Rutenio", "Oro", "Platino", "Rodio"};
	int B[] = {500, 432, 2419, 8483, 12700, 13548, 13548, 40290, 50000, 88416};
	int C[] = {2, 3, 2, 6, 3, 4, 1, 7, 8, 3};

	int n = sizeof(B)/ sizeof(B[0]);

	for (int i = 0; i < n; i++) M.push_back( make_pair(B[i], C[i]) );

	sort(M.begin(), M.end());
	reverse(M.begin(), M.end());

	cin>> a;

	for(int i = 0; i < n; i++){
		if(a > 0){ // 7 > 0 // 4 > 0
			if(a >= M[i].second){// 7 >= 3 // 4 >= 8
				a = a - M[i].second; // a = 7 - 3 = 4
				if(a >= 0){ // 4 >= 0 
					aux = M[i].first * M[i].second; // aux = 265248
					aux1 = aux1 + aux; // aux1 = 0 + 265248
				}
				if(a == 0) break; // 4 == 0
			}
			else{
				aux = a * M[i].first; // aux = 4 * 50000 = 200000
				aux1 = aux1 + aux; // aux1 = 265248 + 465248
				break;
			}
		}
	}

	for(int i = 0; i < M.size(); i++) cout << M[i].first << ", " << M[i].second << endl;

	cout<< endl;
	cout<< aux1<< endl;

	return 0;
}
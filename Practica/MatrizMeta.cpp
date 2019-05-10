#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main(){
	vector< pair< int, int>> M;
	int A [] = {1, 2, 3, 4, 5, 6};
	int B [] = {1, 5, 8, 9, 10, 17};

	int n = sizeof(A)/ sizeof(A[0]);

	for (int i = 0; i < n; i++) M.push_back( make_pair(A[i], B[i]) );

	
	for (int i = 1; i < n; i++){//1 //2 //3 //4 // 5
		for(int j = M[i].first - 1; j > 0; j--){// j = 1 
												// j = 2 / j = 1 
												// j = 3 / j = 2 / j = 1 
												// j = 4 / j = 3 / j = 2 / j = 1 
												// j = 5 / j = 4 / j = 3 / j = 2 / j = 1
			
			int corte = M[i].first - j;// corte = 2 - 1 = 1 
										// corte = 3 - 2 = 1 / corte = 2 - 1 = 1 
										// corte = 4 - 3 = 1 / corte = 4 - 2 = 2 / corte = 4 - 1 = 3 
										// corte = 5 - 4 = 1 / corte = 5 - 3 = 2 / corte = 5 - 2 = 3 / corte = 5 - 1 = 4 
										// corte = 6 - 5 = 1 / corte = 6 - 4 = 2 / corte = 6 - 3 = 3 / corte = 6 -2 = 4 / corte = 6 - 1 = 5
			
			int comple = M[i].first - corte;// comple = 5 - 1 = 4 
											// comple = 3 - 2 = 1 / comple = 2 - 1 = 1 // 
											// comple = 4 - 1 = 3 / comple = 4 - 2 = 2 / comple = 4 - 3 = 1 
											// comple = 5 - 1 = 4 / comple = 5 - 2 = 3 / comple = 5 - 3 = 2 / comple = 5 - 4 = 1 
											// comple = 6 - 1 = 5 / comple = 6 - 2 = 4 / comple = 6 - 3 = 3 / comple = 6 - 4 = 2 / comple = 6 - 5 = 1

			int gan = M[corte - 1].second + M[comple - 1].second; // gan = 1 + 9 = 10 
											// gan = 1 + 1 = 2 / gan = 1 + 1 = 2 //
											// gan = 1 + 8 = 9 / gan = 5 + 5 = 10 / gan = 8 + 1 = 9 
											// gan = 1 + 9 = 10 / gan = 5 + 8 = 13 / gan = 8 + 5 = 13 / gan = 9 + 1 = 10 
											// gan = 1 + 17 = 18 / gan = 5 + 9 = 14 / gan = 8 + 8 = 16 / gan = 9 + 5 = 13 / gan = 10 + 1 = 11

			if (gan > M[i].second) M[i].second = gan;
			// 10 > 5 
			// 2 > 8 / 2 > 8 
			// 9 > 9 / 10 > 9 / 9 > 9 
			// 10 > 10 / 13 > 10 / 13 > 10 / 10 > 10 
			// 18 > 17 / 14 > 17 / 16 > 17 / 13 > 17 / 11 > 17

			// M[1].second = 10
			// = / = 
			// = / M[3].second = 10 / = 
			// = / M[4].second = 13 / M[4].second = 13 / = 
			// M[5].second = 18 / = / = / = / = 
			
		}
    }
	
	cout<< M[3].second<< endl;

	return 0;
}
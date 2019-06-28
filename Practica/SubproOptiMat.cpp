
#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int menor(int a, int b, int c){
	int min;
	if(a < c) min = a;
	else min = c;
	if(min < b) return min;
	else return b;
}

int main(){
	int sm = 6, sn = 5;
	int m = sm + 1;
	int n = sn + 1;

	string a = {"asdfg"}; 
	string b = { "azdgfx"};
	
	int M[5][6];

	for(int i = 0; i < m; i++)
		M[i][0] = i;
	for(int i = 0; i < n; i++)
		M[0][i] = i;
	for(int i = 0; i < m; i++){
		
		for(int j = 0; j < n; j++){
			if(j == 0 || i == 0){
				cout<< M[i][j]<< " ";
				continue;
			}
			if(a[i-1] == b[j-1]){
				M[i][j] = M[i-1][j-1];
			}
			else 
				M[i][j] = menor(M[i][j-1],M[i-1][j-1],M[i-1][j])+1;
			cout<< M[i][j]<< " ";
		}
		cout<<endl;
	}
	int z = m - 1;
	int x = n - 1;
	int res = M[5][6];
	cout<< res;
	return 0;
}
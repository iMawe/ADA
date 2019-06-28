#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


int main(){
	int m, n;
	vector<string> V;
	vector<string> V1;
	string line;

	ifstream in("Doc1.txt");
	ifstream in2("Doc2.txt");

	while(getline(in,line)){
	  	V.push_back(line);
	  	//cout<<line<<endl;
	}
	m = V.size() + 1;
	cout<< endl;
	while(getline(in2,line)){
	  	V1.push_back(line);
	  	//cout<<line<<endl;
	}
	n = V1.size() + 1;

	int M[m][n];

	for(int i = 0; i < m; i++) M[i][0] = 0;
	for(int i = 0; i < n; i++) M[0][i] = 0;

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(j == 0 || i == 0){
				cout<< M[i][j]<< " ";
				//cout<< V[i-1]<<endl;
				continue;
			}
			if(V[i-1] == V1[j-1]){
				M[i][j] = M[i-1][j-1] + 1;
				cout<< V[]
			}
				
			else if(M[i-1][j] >= M[i][j-1]) M[i][j] = M[i-1][j];
			else M[i][j] = M[i][j-1];
			cout<< M[i][j]<< " ";
			}
		cout<< endl;
	}

	cout<< M[m-1][n-1]<< endl;
	return 0;
}
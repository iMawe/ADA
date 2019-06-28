#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<string> cad1;
vector<string> cad2;

int n;
int m;
void calc(){
	int mat[m][n];
	cout<<m<<n<<endl;
	for(int i=0;i<m;i++)
		mat[i][0]=0;
	for(int i=0;i<n;i++)
		mat[0][i]=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(j==0 or i==0){
				cout<<mat[i][j]<<" ";
				continue;
			}
			if(cad1[i-1]==cad2[j-1]){
				mat[i][j]=mat[i-1][j-1]+1;
			}
			else if(mat[i-1][j]>=mat[i][j-1])
				mat[i][j]=mat[i-1][j];
			else 
				mat[i][j]=mat[i][j-1];
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<mat[m-1][n-1];
}
int main(int argc, char const *argv[])
{
	ifstream in("text1.txt");
	ifstream in2("text2.txt");
	string line;
	while(getline(in,line)){
	  	cad1.push_back(line);
	  	cout<<line<<endl;
	}
	m=cad1.size()+1;
	cout<<endl;
	while(getline(in2,line)){
	  	cad2.push_back(line);
	  	cout<<line<<endl;
	}
	n=cad2.size()+1;
	calc();
	
	return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string subcadena = "arequipa";
	int badChar[27];
	cout<<(int)subcadena[7]<<endl;
	badChar[(int)subcadena[7]] = 4;//113
	cout<<badChar[(int)subcadena[7]]<<endl;

	return 0;
}
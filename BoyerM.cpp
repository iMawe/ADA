#include <iostream>
#include <string>
#include <vector>
using namespace std;

static int Max(int a, int b) {
	return a >= b ? a : b;
}

static void SaveSub(string subcadena, int subsize, int* save){
	int i;
	for (i = 0; i < 54; i++)
		save[i] = -1;
	for (i = 0; i < subsize; i++){
		save[(int)subcadena[i]] = i;
		//cout<<(int)subcadena[i]<<" "<<save[(int)subcadena[i]]<<endl;
	}
}

int BoyerM(string cadena, string subcadena){
	int subca = subcadena.length();
	int ca = cadena.length();
	int aux = 0;

	int* save = new int[54];

	SaveSub(subcadena, subca, save);

	int s = 0;
	while (s <= (ca - subca)){//0 <= (14-6)8//1 <= 8//
		int j = subca - 1;//j=5//j=5

		while (j >= 0 && subcadena[j] == cadena[s + j])//5 >= 0 && subcadena[5]C == cadena[0 + 5]A//5>=0 && subcadena[5]C == cadena[1+5]A
			--j;//--//

		if (j < 0){//5 < 0//
			aux = s;//--//--
			s += (s + subca < ca) ? subca - save[cadena[s + subca]] : 1; //--//--
		}
		else
			s += Max(1, j - save[cadena[s + j]]);//s = 0 + Max(1, (5 - 4)) = 1//
		
	}	
	return aux;
}

int main(){
	string data = "AABACAABABACAA";
	int value = BoyerM(data, "ABABAC");

	cout<< "La subcadena empieza en la poscicion : "<< value << endl;
	return 0;
}
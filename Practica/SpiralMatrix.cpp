#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int Funcion(int n, int t, int cont, vector< int> V, int caso){
	int nu = caso;
	while(cont <= n/2){
		if(cont == 0){
			V.push_back(0);
			t = V[cont];
		}
		else{
			int aux = V[cont - 1] + pow(nu - 1, 2) + 1 + pow(nu, 2);
			V.push_back(aux);
			t = V[cont];
			nu += 2;
		}
		cont++;
	}
	return t;
};

void SEspiral(int n){
	int t = 0;
	int cont = 0;
	int aux;
	vector< int> V;
	if(n % 2 == 0){
		aux = Funcion(n, t, cont, V, 2);
	}
	else{
		aux = Funcion(n, t, cont, V, 3);
	}
	cout<< "la suma de la diagonal es:"<< aux<< endl;
};

int main(){
	SEspiral(5);
	return 0;
}/*

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void sumaEspiral(int n)
{
	vector<int>sumitas;
	int total = 0;
	int cont = 0;
	if (n % 2 == 0)
	{
		int num = 2;
		while (cont <= n / 2)
		{
			if (cont == 0)
			{
				sumitas.push_back(0);
				total = sumitas[cont];
			}
			else
			{
				int temp = sumitas[cont - 1] + (pow((num-1),2)+1) + pow(num,2);
				sumitas.push_back(temp);
				total = sumitas[cont];
				num = num + 2;
			}
			cont++;
		}

	}
	else
	{
		int num = 3;
		while (cont <= n / 2)
		{
			if (cont == 0)
			{
				sumitas.push_back(1);
				total = sumitas[cont];
			}
			else
			{
				int temp = sumitas[cont - 1] + (pow((num - 1), 2) + 1) + pow(num, 2);
				sumitas.push_back(temp);
				total = sumitas[cont];
				num = num + 2;
			}
			cont++;
		}
	}

	cout << "la suma de la espiral es -----> "<<total<<endl;
}

int main()
{
	sumaEspiral(5);
	system("pause");
	return 0;
}*/
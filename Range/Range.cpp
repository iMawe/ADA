#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>


using namespace std;

/*
DrawnP(){
	setcolor(4);				
	
	moveto(10, 610);					
	lineto(610, 610);
	moveto(10, 10);					
	lineto(10, 610);
	setcolor(3);
};
*/

int main(){
	/*initwindow(650, 650);
	DrawnP();*/
	int a, b;

	scanf("%i %i", &a, &b); // 4 1

	ofstream os("dibujo.dat");
	vector< pair <int, int>> V;
	int X[] = {1, 4, 4, 2, 3, 5, 7}; 
    int Y[] = {1, 3, 1, 2, 2, 4, 3};




    for(int i = 0; i < 7; i++)
    	os<< X[i]<< " "<< Y[i]<< endl;

    int n = sizeof(X) / sizeof(X[0]);

    for (int i=0; i<n; i++) 
        V.push_back( make_pair(X[i], Y[i]));

	sort(V.begin(), V.end());

	auto aux = make_pair(a, b);


	vector< pair <int, int>>::iterator it = find(V.begin(), V.end(), aux);

	if(!binary_search(V.begin(), V.end(), aux)){
		cout << "No existe\n";
		return 0;
	}

	while(it != V.begin()){
	    if(it->second <= b && it->first <= a) cout<< "("<< it->first<< ", "<< it->second<< ")"<< endl;
	    
        it--;
    }

    if(it == V.begin()) cout<< "("<< it->first<< ", "<< it->second<< ")"<< endl;

	//cout<< it->first << endl;
/*	
	cout << "The vector after sort operation is:\n" ; 
    for (int i=0; i<n; i++){ 
        cout << V[i].first << " "
             << V[i].second << endl; 
    }
	*/
//plot 'C:\Users\Mauricio\Documents\GitHub\ADA\ADA\Range\dibujo.dat' using 1:2:(sprintf("(%d, %d)", $1, $2)) with labels point pt 7 offset char 1,1 notitl

  	//while(!kbhit()) delay(1);
    return 0; 

}
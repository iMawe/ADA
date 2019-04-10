#include <iostream>
#include <vector>
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

	vector< pair <int, int>> V;
	int X[] = {1, 4, 4, 2, 3, 5}; 
    int Y[] = {1, 3, 1, 2, 2, 4};

    int n = sizeof(X) / sizeof(X[0]);

    for (int i=0; i<n; i++) 
        V.push_back( make_pair(X[i], Y[i]));

	sort(V.begin(), V.end());

	auto aux = make_pair(a, b);


	vector< pair <int, int>>::iterator it = find(V.begin(), V.end(), aux);

	while(it + 1 != V.begin()){
        if(it->second <= b) cout<< "("<< it->first<< ", "<< it->second<< ")"<< endl;
        if(it->first <= a) cout<< "("<< it->first<< ", "<< it->second<< ")"<< endl;
        it--;
    }

	//cout<< it->first << endl;
/*	
	cout << "The vector after sort operation is:\n" ; 
    for (int i=0; i<n; i++){ 
        cout << V[i].first << " "
             << V[i].second << endl; 
    }
	*/


  	//while(!kbhit()) delay(1);
    return 0; 

}
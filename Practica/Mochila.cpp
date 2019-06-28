#include <iostream>
using namespace std;

int main(){ 
    int cantMo = 6, pesoMo = 6;
    int max1 = -1, re = 0;
    cantMo = cantMo + 1;
    pesoMo = pesoMo + 1;
    int Mo[cantMo][pesoMo];
    int w[cantMo + 1] = {0, 1, 2, 6, 3, 4, 5};
    int g[cantMo + 1] = {0, 1, 2, 3, 4, 5, 6};

    for(int i = 0; i < pesoMo; i++){
            Mo[0][i] = 0;
            if(i < cantMo) Mo[i][0] = 0;
    }       
    for(int i = 1; i <= cantMo - 1; ++i){
        for(int j = 1; j <= pesoMo - 1; ++j){
            if(j - w[i] < 0) Mo[i][j] = Mo[i - 1][j];

            else Mo[i][j] = max(Mo[i - 1][j], Mo[i - 1][j - w[i]] + g[i]);
        }
    }
    cout<< endl;

    
    for(int i = 0; i < cantMo; ++i){
        for(int j = 0; j < pesoMo; ++j){
            cout<< Mo[i][j]<< " ";
            if(Mo[i][j] > max1){
                max1 = Mo[i][j];
                re = Mo[i][j];
            }   
        }
        cout<< "\n";
    }

    cout<< endl;
    cout<< re<< endl;


    return 0;
}

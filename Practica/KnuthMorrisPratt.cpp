#include <iostream>
#include <string>
#include <vector>

using namespace std;

int kmp(const string &T, const string &P) {//ABABDABACDABABCABAB, ABABCABAB
    if (P.empty()) return 0;
                                 //Fallo = {0,0,0,0,0,0,0,0}//Fallo = {0,0,0,0,0,0,0,0}//Fallo = {0,0,1,2,0,0,0,0}
    vector<int> Fallo(P.size(), 0); //Fallo = {0,0,1,2,0,0,0,0}//Fallo = {0,0,1,2,0,1,0,0}//Fallo = {0,0,1,2,0,1,0,0}
                                 //Fallo = {0,0,1,2,0,1,1,0}//Fallo = {0,0,1,2,0,1,0,0}

    for (int i = 1, k = 0; i < P.size(); ++i){//i=1, k=0//i=2, k=0//i=3. k=1//i=4, k=2//i=5, k=0//i=6, k=1//i=7, k=0//i=8, k=1
        while (k && P[k] != P[i])//0 && P[0]A != P[1]B//0 && P[0]A != P[2]A//1 && P[1]B != P[3]B//2 && P[2]A != P[4]C
                                 //0 && P[0]A != P[5]A//1 && P[1] != P[6]B//0 //1&&P[1]B != P[8]B
            k = Fallo[k - 1]; //--//--//--//k = 0//--//k=0/--//k=0
        if (P[k] == P[i]) //P[0]A == P[1]B//P[0]A == P[2]A//P[1]B == P[3]B//P[2]A == P[4]C//P[0]A == P[5]A// P[0]A == P[6]B// P[0]A == P[7]A// P[0]A == P[8]B
            ++k;// k = 0// k = 1// k = 2//k=0// k=1//k=0//k=1//--
        Fallo[i] = k; //Fallo[1] = 0//Fallo[2] = 1//Fallo[3] = 2//Fallo[4] = 2// Fallo[5] = 1//Fallo[6]=0//Fallo[7]=1//Fallo[8]=0
    }

    for (int i = 0, k = 0; i < T.size(); ++i){//i=0, k=0//i=1, k=1//i=2, k=2//i=3, k=3//i=4, k=4
        while (k && P[k] != T[i])//0//1&&P[1]B != T[1]B//2&&P[2]A != T[2]A//--//4 && P[4]C != T[4]D
            k = Fallo[k - 1];//--//--//--//--//k = Fallo[4-1] 2

        if (P[k] == T[i]) //P[0]A == T[0]A//P[1]B == T[1]B//P[2]A==T[2]A//==//P[2]A == T[4]D
            ++k;//k=1//k=2//k=3//k=4//k=2

        if (k == P.size()) //1 == 19//2 == 19//3==19//4=19//2==19//
            return i - k + 1;
    }
    return -1;
}

int kmp2(const string &cadena, const string &subcadena){
    
}

int main(){
    string txt = "ABABDABACDABABCABAB"; 
    string subc = "ABABCABAB";
    int x = 0;

    x = kmp (txt, subc);

    cout<< "La subcadena empieza en la poscicion : "<< x << endl;

    return 0;
}
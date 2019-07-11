#include <iostream>
#include <string>
#include <vector>

using namespace std;

static vector<int> KarpRabin(string A, string B) {
    vector<int> retVal;

    int siga = 0;
    int sigb = 0;
    int Q = 99999;
    int D = 256;
    int ALength = A.length();
    int BLength = B.length();

    for (int i = 0; i < BLength; ++i){
        siga = (siga * D + (int)A[i]) % Q;//hashing
        sigb = (sigb * D + (int)B[i]) % Q;//hashing
    }

    if (siga == sigb)
        retVal.push_back(0);

    int pow = 1;

    for (int k = 1; k <= BLength - 1; ++k)
        pow = (pow * D) % Q;

    for (int j = 1; j <= ALength - BLength; ++j){
        siga = (siga + Q - pow * (int)A[j - 1] % Q) % Q;//rehashing
        siga = (siga * D + (int)A[j + BLength - 1]) % Q;//rehashing

        if (siga == sigb)
            if (A.substr(j, BLength) == B)
                retVal.push_back(j);
    }

    return retVal;
}

int main(){
    string data = "AABACAABABACAA";
    vector<int> value = KarpRabin(data, "ABABAC");

    cout<< value[0] << endl;

    return 0;
}
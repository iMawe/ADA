#include <iostream>

using namespace std;

string V[5] = {"laptop equipo parlante cables lapicero ",
            "ventana mochila cables mouse iglesia ",
            "audifonos juego parlante cabello lapicero ",
            "juego equipo lapicero ojos cables ",
            "mouse libro laptop lampara juego "};

int main(){
  string aux="";
    int j = -1;
    int ii = 0;
  for(int i = 0; i < 5; i++){
    for(int p = 0; i < 5; i++){
      j = V[i].find(" ",j + 1) - 1;

      for(int k = ii; k < = j; k++)
        aux += V[i][k];
      cout<< aux;
      //aqui hagamos que compare con las demas palabras
      
      for(int l = i + 1; l < 5; l++){
        int found = V[l].find(aux);
        if (found != std::string::npos){
          cout<< " imagen "<< l + 1<< " hay "<< aux<< endl;
        }
      }
      

      cout<< aux<< endl;
      aux = "";
      ii = j + 2;
    }
    j =- 1;
  }
}
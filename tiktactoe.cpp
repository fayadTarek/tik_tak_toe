#include <iostream>
#include <array>
using namespace std;
enum joueur {X, O, vide};

typedef array<array<joueur ,3>,3> tik;


tik initialise ( tik &ar){
    for (size_t i = 0; i <= ar.size(); i++)
    {
        for (size_t t = 0; t <= ar[i].size(); t++)
        {
            ar[i][t] = vide;
        }   
    }
    return ar;
}

void print(tik ar){
   
  for(auto colonne :ar){
    for (size_t i = 0; i < colonne.size(); i++)
    {
         if(colonne[i] == vide){
            cout << " ";
        }else if(colonne[i] == X){
            cout << "X";
        }else if(colonne[i] == O){
            cout << "O";
        }
        if(i < 2){
            cout << " | ";
        }
    }
    
    cout << endl;
  }

    for (size_t i = 1; i < 4; i++)
    {
        cout << i << "   ";
    }
    
    
}

int main (){
    tik grille;
    initialise(grille);
     grille [1][0] = X;
     grille [1][1] = X;
    print (grille);

    return 0;
}
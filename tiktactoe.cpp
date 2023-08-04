#include <iostream>
#include <array>
using namespace std;
enum joueur {X, O, vide};

typedef array<array<joueur ,2>,2> tik;


tik initialise ( tik ar){
    for(auto ligne: ar){
        for(auto colonne : ligne){
            colonne = vide;
        }
    }
    return ar;
}

void print(tik ar){
    for (size_t i = 0; i <= ar.size(); i++)
    {
        for (size_t t = 0; t <= ar[i].size(); t++)
        {
            switch (ar[i][t])
            {
            case X:
                cout << "X";
                break;
            case O:
                cout << "O";
                break;
            case vide:
                cout <<" ";
                break;
            }
            if(t < 2){
                cout << " | ";
            }
        }
        cout << endl;
    }
    
}

int main (){
    tik grille;
    initialise(grille);
    print (grille);

    return 0;
}
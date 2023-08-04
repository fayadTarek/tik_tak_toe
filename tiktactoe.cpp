#include <iostream>
#include <array>
using namespace std;
enum joueur {X, O, vide};

typedef array<array<joueur ,3>,3> tik;
tik initialise ( tik &ar);
void print(tik ar);
void joue(bool jouer , tik &ar);
bool joueurInpute(size_t colonne , size_t ligne , tik ar);


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
    cout << endl << endl;
    
}

void joue(bool jouer , tik &ar){
    joueur Joueur;

    if(jouer == true){
        Joueur = X;
    }else{
        Joueur = O;
    }

    size_t colonne;
    size_t ligne;

    do
    {
        cout << ">entrez le colonne :";
        cin >> colonne;
        cout << ">entrez le ligne :";
        cin >> ligne;
    } while (not joueurInpute(colonne,ligne,ar));
    ar[ligne-1][colonne-1] = Joueur;
}

bool joueurInpute(size_t colonne , size_t ligne , tik ar){
    
    if(((colonne > ar.size()) || (ligne > ar[0].size()))){
        cout << "le position est foux " << endl;
        return false;
    }else if((ar[colonne-1][ligne-1] !=vide)){
        cout << "l'espace est plein " << endl;
        return false;
    }else{
        return true;
    }

    
}

int main (){
    bool tour = true;
    tik grille;
    initialise(grille);
    grille[2][2] = O;
    print (grille);
    joue(true, grille);
    print(grille);

    return 0;
}
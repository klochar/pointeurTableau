#include <iostream>
#include "Voiture.hpp"
#include "Liste1.hpp"

using namespace std;

int main (){
    Voiture v1(4,"rouge","Toyota");
    Voiture v2(4,"blue","honda");
    Voiture v3(4,"gris","acura");
    Liste1<Voiture> l1;
    l1.ajouter(v1);
    l1.ajouter(v2);
    l1.ajouter(v3);
    l1.afficher();


    //exemple de tableau de pointeur unique_ptr<unique_ptr<T>[]>

    // unique_ptr<unique_ptr<int>[]> tableau = make_unique<unique_ptr<int>[]>(3);
    // unique_ptr<int> ptrA = make_unique<int> (2);
    // unique_ptr<int> ptrB = make_unique<int> (3);
    // unique_ptr<int> ptrC = make_unique<int> (4);

    // tableau[0] = move(ptrA);
    // tableau[1] = move(ptrB);
    // tableau[2] = move(ptrC);

    // cout<<*tableau[1];


    return 0;
}

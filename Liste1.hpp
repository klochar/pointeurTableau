#include <memory>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Liste1{
public:
    Liste1(){}//constructeur
    Liste1(const Liste1& l1);//constructeur de copie
    void ajouter(const T& element){
        if (nbElement==capacite){//faudra grandir, mais faire atention lorsque capacite vaut 0
            int nouvelleCapacite = std::max(this->capacite*2,1);
            augmenterCapacite(nouvelleCapacite);
            unique_ptr<T> ptrElement = make_unique<T>(element);
            tableau[nbElement++] = move(ptrElement);
        } else {
            unique_ptr<T> ptrElement = make_unique<T>(element);
            tableau[nbElement++] = move(ptrElement);
        } 
    }
    void augmenterCapacite(int nouvelleCapacite){
        if(nouvelleCapacite >= this->capacite){//normal
            unique_ptr<unique_ptr<T>[]> nouveauTab = make_unique<unique_ptr<T>[]>(nouvelleCapacite);
            for(int i =0;i<this->nbElement;i++){
                nouveauTab[i] = move(this->tableau[i]);
            }
            this->capacite = nouvelleCapacite;
            this->tableau = move(nouveauTab);
        } else {
            unique_ptr<unique_ptr<T>[]> nouveauTab = make_unique<unique_ptr<T>[]>(nouvelleCapacite);
            for(int i =0;i<nouvelleCapacite;i++){
                nouveauTab[i] = move(this->tableau[i]);
            }
            this->capacite = nouvelleCapacite;
            this->tableau = move(nouveauTab);
        }
    }
    friend std::ostream& operator<<(std::ostream& out, const Liste1& l1){
        for(auto i : l1){   
            out<<i;//le i utlisera le operateur<< du type T
        }
        return out;
    }

    void afficher(){
        for (int i =0 ; i<nbElement;i++){
            cout<<*tableau[i]<<endl;
        }
    }




private: 
int nbElement=0;
int capacite=0;
std::unique_ptr<std::unique_ptr<T>[]> tableau ;




};
#include <iostream>
#include <string>
#include <memory>
#include <fstream>

class Voiture{
public:
    
    Voiture(int,std::string,std::string);

    friend std::ostream& operator<<(std::ostream& out,const Voiture& voiture){
        out<<"marque : "<<voiture.marque<<std::endl<<
                            "couleur : "<<voiture.couleur
                            <<std::endl;
        return out;
    }
    


private:
    int nbRoue=4;
    std::string couleur;
    std::string marque;


};
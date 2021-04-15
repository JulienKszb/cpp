#ifndef TD2_hpp
#define TD2_hpp

#include <iostream>
using namespace std;

class vecteur
{
public:
    vecteur();
    vecteur(const int nb);
    vecteur(const int nb, const float * val);
    vecteur(const vecteur & copie);
    
    virtual ~vecteur();
    
    void afficher();
    void saisir();
    
    float & operator [] (int indice);
    vecteur & operator = (const  vecteur & v);
    vecteur & operator += (const vecteur & v);
    
    int getdim();
    float & getelement();

protected:
    float * element;
    int dim;
};

vecteur operator + (vecteur & v2, vecteur & v3);

#endif

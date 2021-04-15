#ifndef TD5_hpp
#define TD5_hpp

#include <iostream>
using namespace std;

enum vecterr{index_err,dimension_err};

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
    
    friend vecteur operator * (float f, vecteur & v);

protected:
    float * element;
    int dim;
};

vecteur operator + (vecteur & v2, vecteur & v3);

class Matrice
{
public:
    vecteur * Tab[10] ;
    Matrice();
    void affichage();
};
#endif

#ifndef TD4_hpp
#define TD4_hpp

#include <iostream>
using namespace std;

template <class T> class vecteur
{
public:
    vecteur();
    vecteur(int nb);
    vecteur(int nb, T * val);
    vecteur(const vecteur & copie);
    ~vecteur();
    void afficher();
    void saisir();
    T & operator [] (int indice);
    vecteur<T> & operator = (const vecteur & v);
    int getdim();
    vecteur & operator += (const vecteur & v);
protected:
    T * element;
    int dim;
};


template <class T> ostream & operator << (ostream& os, vecteur<T> & v);

template <class T> istream & operator >> (istream& is, vecteur<T> & v);



#endif

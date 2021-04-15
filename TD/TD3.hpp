#ifndef TD3_hpp
#define TD3_hpp

#include "TD2.hpp"

class vecteur_intel : public vecteur
{
public:
    vecteur_intel();
    vecteur_intel(const int nb);
    vecteur_intel(const int nb, const float * val);
    vecteur_intel(const vecteur_intel & copie);
    
    virtual ~vecteur_intel() {};
    
    vecteur_intel & operator = (const  vecteur_intel & v);
    vecteur_intel & operator += (const vecteur_intel & v);
};

vecteur_intel & operator +(const vecteur_intel & v1, const vecteur_intel & v2);
#endif

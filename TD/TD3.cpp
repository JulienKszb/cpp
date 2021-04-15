#include "TD3.hpp"

#include <iostream>
using namespace std;

vecteur_intel::vecteur_intel(): vecteur() {}

vecteur_intel::vecteur_intel(const int nb) : vecteur(nb) {}

vecteur_intel::vecteur_intel(const int nb , const float * val) : vecteur(nb,val) {}

vecteur_intel::vecteur_intel(const vecteur_intel & copie) : vecteur(copie) {}

vecteur_intel & vecteur_intel::operator = (const vecteur_intel & v)
{
      if(dim != v.dim)
      {
/*        Correction
          if (dim!=0) delete [] element;
          if(!(element=new float[v.dim]))
          {
              cout << "erreur allocation \n";
              exit(0);
          }
          dim=v.dim;
*/
          element=new float[v.dim];
          dim=v.dim;
      }
      for (int i=0;i<dim;i++){element[i]=v.element[i];}
      return(*this);
}

vecteur_intel & vecteur_intel::operator += (const vecteur_intel & v)
{
    if (dim < v.dim)
    {
        float * aux;
        if(!(aux=new float[v.dim]))
        {
            cout << "erreur allocation \n";
            exit(0);
        }
        for (int i=0;i<dim;i++) {aux[i]=v.element[i]+element[i];}
        for (int i=dim;i<v.dim;i++) {aux[i]=v.element[i];}
        delete [] element;
        element=aux;
        dim=v.dim;
    }
    else {for (int i=0;i<v.dim;i++) element[i]+=v.element[i];}
    
    return (*this);
}

vecteur_intel & operator +(const vecteur_intel & v1, const vecteur_intel & v2)
{
    vecteur_intel temp(v1);
    temp.vecteur_intel::operator += (v2);
    return temp;
    // après test, temp est considéré comme une variable locale...
}

int main()
{
    float f[5];
    float g[10];
    for(int i=0;i<5;i++) {f[i]=i;}
    for(int i=0;i<10;i++) {g[i]=1.;}
    
    vecteur_intel v1;
    vecteur_intel v2(5,f);
    vecteur_intel v3(10,g);
    
    cout << "v1 vaut : ";
    v1.afficher();
    cout << endl << "v2 vaut : ";
    v2.afficher();
    cout << endl << "v3 vaut : ";
    v3.afficher();
    cout << endl << endl;
    
    cout <<"Etudions l'opérateur = " << endl;
    cout <<"v1=v2 vaut : ";
    v1=v2;
    v1.afficher();
    cout << "Remettons v1 à nul avec aux le vecteur nul, v1 vaut : ";
    vecteur_intel aux;
    v1=aux;
    v1.afficher();
    cout << endl << endl;
    
    cout <<"Etudions l'opérateur += " << endl;
    aux=v2;
    cout <<"v2+=v3 vaut : ";
    v2+=v3;
    v2.afficher();
    v2=aux;
    aux=v3;
    cout << endl <<"v3+=v2 vaut : ";
    v3+=v2;
    v3.afficher();
    v3=aux;
    cout << endl << endl;
    
    cout <<"Etudions l'opérateur + " << endl;
    // Ce dernier test ne fonctionne pas
    v1=v2+v3;
    cout <<"v1=v2+v3 vaut : ";
    v1.afficher();
    
    
    
    
    return 0;
}

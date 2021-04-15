//
//  TD1.cpp
//  TD
//
//  Created by Julien KASZUBA on 04/02/2021.
//

#include "TD1.hpp"
#include <iostream>

using namespace std;

class vecteur {
private:
    
    float * element;
    int dim;
    
public:
    vecteur()
    {
        element=NULL;
        dim=0;
    }
    
    
    vecteur(int nb , float val = 0.)
    {
        element=new float[nb];
        dim=nb;
        for(int i=0;i<nb;i++)
        {
            element[i]=val;
        }
    }
    
    vecteur(const vecteur & copie)
    {
        dim=copie.dim;
        element=new float[dim];
        for(int i=0;i<dim;i++)
        {
            element[i]=copie.element[i];
        }
    }
    
    
    ~vecteur()
    {
        delete element;
        dim=0;
    }
    
    // Pour moi, les fonctions afficher et saisir doivent être à l'intérieur de la classe car elles ont besoin d'avoir accès à variables privates pour fonctionner. Nous pouvons les sortir de la classe à condition de définir des fonctions getdim et getelement dans la classe.
    
    void afficher()
    {
        for(int i=0;i<dim;i++)
        {
            cout<<element[i]<<" ";
        }
        cout << endl;
    }
    
    void saisir()
    {
        cout << "Quelle taille fait votre vecteur ?" << endl;
        cin >> dim;
        // Si l'entrée n'est pas un int, le main s'arrête
        element=new float[dim];
        cout << "Ecrivez une à une les composantes de votre vecteur." << endl;
        for(int i=0;i<dim;i++)
        {
            cin >> element[i];
        }
    }
};


int main()
{
    vecteur v1;
    v1.afficher();
    // N'affiche rien
    vecteur v2(10);
    v2.afficher();
    // N'affiche que 10 fois la valeur par défaut
    vecteur v3(10,4);
    v3.afficher();
    // Affiche bien 10 fois le float 4
    vecteur v4(v3);
    v4.afficher();
    // La copie est bien effectuée
    vecteur v5;
    v5.saisir();
    v5.afficher();
    // La fonction saisie fonctionne bien

    return 0;
}

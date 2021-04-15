

#include "TP1.hpp"
#include <iostream>
#include <math.h>

int Figure::cpt=0;

Figure::Figure(){cpt+=1;}

Polygone::Polygone(int nb){nbCotes=nb;}

void Polygone::afficherCaracteristiques(){cout << "Le polygone a "<< nbCotes <<" cotés"<<endl;}

Rectangle::Rectangle(int lo, int la) : Polygone(4)
{
    longueur=lo;
    largeur=la;
}

void Rectangle::put(int lo, int la)
{
    longueur=lo;
    largeur=la;
}

int Rectangle::getlongueur(){return longueur;}
int Rectangle::getlargeur(){return largeur;}

int Rectangle::perimetre(){return 2*longueur+2*largeur;}

void Rectangle::afficherCaracteristiques()
{
    cout << "Le périmètre du rectangle vaut : " << perimetre()<<endl;
    cout << "Le rectangle a une longueur de "<< longueur <<" et une largeur de "<< largeur <<endl;
}

Carre::Carre(int cote) : Rectangle(cote,cote) {}

TriangleEquilateral::TriangleEquilateral(int cote):Polygone(3)
{
    longueur=cote;
}

void TriangleEquilateral::put(int cote){longueur=cote;}
int TriangleEquilateral::getcote(){return longueur;}

int TriangleEquilateral::perimetre(){return 3*longueur;}
void TriangleEquilateral::afficherCaracteristiques()
{
    cout << "Le périmètre du triangle équilatéral vaut : " << perimetre()<<endl;
    cout << "Le triangle équilatéral a une longueur de "<< longueur <<endl;
}

Cercle::Cercle(int r,string coul):Coloriable(coul)
{
    rayon=r;
    couleur=coul;
}

void Cercle::put(int r){rayon=r;}
int Cercle::get(){return rayon;}

int Cercle::perimetre(){return 2*M_PI*rayon;}
void Cercle::afficherCaracteristiques()
{
    cout << "Le périmètre du cercle vaut : " << perimetre()<<endl;
    cout << "Le cercle a un rayon de "<< rayon <<endl;
    cout << "La couleur du cercle est : " << couleur <<endl;
}

Coloriable::Coloriable (string coul) {couleur=coul;}
string Coloriable::getCouleur() {return couleur;}
void Coloriable::setCouleur(string coul) {couleur=coul;}

template <class T> void File<T>::inserer(Cellule<T> valeur)
{
    last->suiv=new Cellule<T>(valeur);
    last=last->suiv;
    if(nb==0) {first=last;}
    nb++;
}

template <class T> void File<T>::supprimer()
{
    if(nb!=0){
        Cellule<T>  aux;
        aux=first;
        delete(aux);
        if(nb>1) {first->suiv=first->suiv;}
        else {first=NULL;last=NULL;}
        nb--;
    }
    else {
        //faire une erreur
    }
}

template <class T> int File<T>::vide()
{
    int vide=0;
    if(nb==0) {vide=1;}
    return vide;
}

template <class T> Cellule<T> File<T>::tete() {return *first;}
template <class T> Cellule<T> File<T>::queue() {return *last;}
template <class T> int File<T>::nombre() {return nb;}


int main()
{
    /*
    Figure * Tab[3];
    Tab[0]=new Carre(4);
    Tab[1]=new Cercle(3,"vert");
    Tab[2]=new TriangleEquilateral(2);
    
    for(int i=0;i<3;i++) {Tab[i]->afficherCaracteristiques();}
    
    cout << "Il y a " << Figure::cpt << " figures dans le tableau" << endl;
    
    cout << endl << endl << endl <<endl ;
    */
    Figure * Tab[3];
    Tab[0]=new Carre(4);
    Tab[1]=new Cercle(3,"vert");
    Tab[2]=new TriangleEquilateral(2);
    
    Carre car(4);
    
    //Cellule<Figure> $ C(car);
    
    File<Figure *> F;
    
    Cellule<Figure*> carbis(&car);

    F.inserer(carbis);
    

    
    
    return 0;
}

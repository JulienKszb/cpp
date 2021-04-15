
#pragma once

#include <stdio.h>
#include <string>
#include <stdexcept>
using namespace std;

class Figure
{
public:
    Figure();
    static int cpt;
    virtual int perimetre()=0;
    virtual void afficherCaracteristiques()=0;
};

class Polygone : public Figure
{
protected:
    int nbCotes;
public:
    Polygone(int nb);
    virtual ~Polygone() {};
    virtual void afficherCaracteristiques() override;
};

class Rectangle : public Polygone
{
protected:
    int longueur;
    int largeur;
public:
    Rectangle(int lo, int la);
    virtual ~Rectangle(){};
    void put(int lo, int la);
    int getlongueur();
    int getlargeur();
    virtual int perimetre() override;
    virtual void afficherCaracteristiques() override;
};

class Carre : public Rectangle
{
public:
    Carre(int cote);
    virtual ~Carre(){};
};

class TriangleEquilateral : public Polygone
{
protected:
    int longueur;
public:
    TriangleEquilateral(int cote);
    virtual ~TriangleEquilateral(){};
    void put(int cote);
    int getcote();
    virtual int perimetre() override;
    virtual void afficherCaracteristiques() override;
};

class Coloriable {
protected:
    string couleur;
public:
    Coloriable (string coul);
    string getCouleur();
    void setCouleur(string coul);
};

class Cercle : public Figure , Coloriable
{
protected:
    int rayon;
public:
    Cercle(int r, string coul);
    virtual ~Cercle(){};
    void put(int r);
    int get();
    virtual int perimetre() override;
    virtual void afficherCaracteristiques() override;
};

template <class T> class File;

template <class T> class Cellule
{
protected:
    T val;
    Cellule<T> * suiv;
public:
    Cellule(T valeur) {val=valeur;suiv=NULL;};
    friend File<T>;
};

template <class T> class File
{
protected:
    Cellule<T> * first;
    Cellule<T> * last;
    int nb;
public:
    File() {first=NULL;last=NULL;nb=0;};
    void inserer(Cellule<T> valeur);
    void supprimer();
    int vide();
    Cellule<T> tete();
    Cellule<T> queue();
    int nombre();
    
    //class Vide : public ;
};

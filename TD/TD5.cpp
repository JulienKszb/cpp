#include "TD5.hpp"

vecteur::vecteur()
{
    element=NULL;
    dim=0;
}

vecteur::vecteur(const int nb)
{
    element=new float[nb];
    dim=nb;
}

vecteur::vecteur(const int nb, const float * val)
{
    element=new float[nb];
    dim=nb;
    for(int i=0;i<nb;i++)
    {
        element[i]=val[i];
    }
}

vecteur::vecteur(const vecteur & copie)
{
    dim=copie.dim;
    element=new float[dim];
    for(int i=0;i<dim;i++)
    {
        element[i]=copie.element[i];
    }
}


vecteur::~vecteur()
{
    if(dim>0)
    {
        delete [] element;
    }
}

// Pour moi, les fonctions afficher et saisir doivent être à l'intérieur de la classe car elles ont besoin d'avoir accès à variables privates pour fonctionner. Nous pouvons les sortir de la classe à condition de définir des fonctions getdim et getelement dans la classe.

void vecteur::afficher()
{
    for(int i=0;i<dim;i++)
    {
        cout<<element[i]<<" ";
    }
    cout << endl;
}

void vecteur::saisir()
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

float & vecteur::operator [] (int indice)
{
    if(indice<0 || indice >=dim) {throw index_err;}
    return this->element[indice];}


vecteur & vecteur::operator = (const vecteur & v)
{
    if(dim != v.dim) {throw dimension_err;}
    memcpy(element,v.element,dim*sizeof(float));
    return *this;
}

int vecteur::getdim()
{
    return dim;
}

float & vecteur::getelement()
{
    return *this->element;
}

vecteur & vecteur::operator += (const vecteur & v)
{
    if(dim!=v.dim) {throw dimension_err;}
    else
    {
        for(int i=0;i<dim;i++)
        {
            element[i]+=v.element[i];
        }
        return *this;
    }
}


vecteur operator + ( vecteur & v1, vecteur & v2)
{
    vecteur temp(v1);
    temp+=v2;
    return temp;
}


vecteur operator * (float f, vecteur & v)
{
    vecteur aux(v);
    for(int i=0;i<v.dim;i++){v.element[i]=v.element[i]*f;}
    return v;
}

Matrice::Matrice() {
    for(int i=0;i<10;i++) {Tab[i]=0;}
}

void Matrice::affichage() {
    for(int i=0; i<10; i++) {Tab[i]->afficher();}
}


int main()
{

    try {
        vecteur v1(3),v2(3),v3(2);
        v2[0]=1;
        v2[1]=2;
        v2[2]=3;
        cout << "v2 vaut : ";
        v2.afficher();
        cout << "Regardons si la fonction multiscalaire fonction en multipliant v2 par 3.2." <<endl;
        v2=3.2*v2;
        cout << "v2 vaut : " ;
        v2.afficher();
    }
    catch(enum vecterr err) {
        switch(err) {
            case dimension_err:
                cout << "La dimension n'est pas la bonne mec" << endl ;
                break;
            case index_err:
                cout << "L'index n'est pas le bon mec" << endl;
                break;
        }
    }
    
    
    try {
        vecteur v1(3),v2(3),v3(2);
        v2[0]=1;
        v2[1]=2;
        v2[2]=3;
        cout << endl;
        cout << "v2 vaut : ";
        v2.afficher();
        cout << "Accédons à v2[5] qui est innaccessible car v2.dim=3. " << endl;
        cout << v2[5];
        cout << "v3 vaut : ";
        v3.afficher();
        //v3=v2;
    }
    catch(enum vecterr err) {
        switch(err) {
            case dimension_err:
                cout << "La dimension n'est pas la bonne mec" << endl ;
                break;
            case index_err:
                cout << "L'index n'est pas le bon mec" << endl;
                break;
        }
    }
    
    try {
        vecteur v1(3),v2(3),v3(2);
        v2[0]=1;
        v2[1]=2;
        v2[2]=3;
        cout << endl;
        cout << "v2 vaut : ";
        v2.afficher();
        cout << "Testons si v3=v2 fonctionne alors qu'ils n'ont pas les mêmes dimensions. " << endl;
        cout << "v3 vaut : ";
        v3=v2;
        v3.afficher();

    }
    catch(enum vecterr err) {
        switch(err) {
            case dimension_err:
                cout << "La dimension n'est pas la bonne mec" << endl ;
                break;
            case index_err:
                cout << "L'index n'est pas le bon mec" << endl;
                break;
        }
    }

    Matrice M;
    vecteur v1(3),v2(3),v3(2),v4;
    v2[0]=1;
    v2[1]=2;
    v2[2]=3;
    v4=3.2*v2;
    M.Tab[0]=&v1;
    M.Tab[1]=&v2;
    M.Tab[2]=&v3;
    M.Tab[3]=&v4;
    M.Tab[0]->afficher();
    M.Tab[1]->afficher();
    M.Tab[2]->afficher();
    M.Tab[3]->afficher();
    M.affichage();
    
    // Je n'y arrive pas, je ne comprends pas pourquoi

        
    return 0;
}


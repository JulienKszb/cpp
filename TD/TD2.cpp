#include "TD2.hpp"

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

float & vecteur::operator [] (int indice) {return this->element[indice];}


vecteur & vecteur::operator = (const vecteur & v)
{
    if(dim != v.dim)
    {
       cout << "dimension incompatible \n";
       exit(0);
    }
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
    if(dim!=v.dim)
    {
        cout << "Dimension non identique \n";
        exit(0);
    }
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



/*
int main()
{
    // Question 1
    vecteur v1(10);
    v1.afficher();
    cout << endl << "Regardons désormais si l'opérateur [] marche bien." << endl;
    v1[3]=3.5;
    float f;
    f=v1[3];
    cout << "v2 vaut désormais" << endl;
    v1.afficher();
    cout << endl << "De plus, f vaut : " << f << endl << endl << endl;
    
    // Question 2
    vecteur v2(3),v3(3);
    v2[0]=1;
    v2[1]=2;
    v2[2]=3;
    cout << "v2 vaut : ";
    v2.afficher();
    cout << endl;
    cout << "v3 vaut : ";
    v3.afficher();
    cout << endl;
    cout << "Après opération v3=v2, v3 vaut : ";
    //v3.operator=(v2);
    v3=v2;
    // les deux opérateurs marchent
    v3.afficher();
    cout << endl << endl << endl;
    
    // Question 3
    float c[3];
    c[0]=1.;
    c[1]=2.2;
    c[2]=4.;
    vecteur v4(3,c);
    cout << "v3 vaut : ";
    v3.afficher();
    cout << endl;
    cout << "v4 vaut : ";
    v4.afficher();
    cout << endl << endl;
    
    vecteur v5(3);
    v5=v3+v4;
    //v5=operator + (v3,v4);
    cout << "v5=v3+v4 vaut : ";
    v5.afficher();
    cout << endl << endl;
    
    
    v3+=v4;
    //v3.operator+=(v4);
    cout << "v3+=v4 vaut : ";
    v3.afficher();
    cout << endl;
    // L'opérateur += fonctionne bien
    return 0;
}
*/

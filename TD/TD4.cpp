#include "TD4.hpp"



template <class T> vecteur<T>::vecteur()
{
    element=NULL;
    dim=0;
}

template <class T> vecteur<T>::vecteur(int nb)
{
    element=new T[nb];
    dim=nb;
}

template <class T> vecteur<T>::vecteur(int nb , T * val)
{
    element=new T[nb];
    dim=nb;
    for(int i=0;i<nb;i++) {element[i]=val[i];}
}

template <class T> vecteur<T>::vecteur(const vecteur & copie)
{
    dim=copie.dim;
    element=new T[dim];
    for(int i=0;i<dim;i++) {element[i]=copie.element[i];}
}

template <class T> vecteur<T>::~vecteur()
{
    if(dim>0)
    {
        delete [] element;
    }
}

template <class T> void vecteur<T>::afficher()
{
    for(int i=0;i<dim;i++) {cout<<element[i]<<" ";}
    cout << endl;
}

template <class T> void vecteur<T>::saisir()
{
    cout << "Quelle taille fait votre vecteur ?" << endl;
    cin >> dim;
    // Si l'entrée n'est pas un int, le main s'arrête
    element=new T[dim];
    cout << "Ecrivez une à une les composantes de votre vecteur." << endl;
    for(int i=0;i<dim;i++)
    {
        cin >> element[i];
    }
}

template <class T> T & vecteur<T>::operator [] (int indice) {return this->element[indice];}


template <class T> vecteur<T> & vecteur<T>::operator = (const vecteur & v)
{
    if(dim != v.dim)
    {
       cout << "dimension incompatible \n";
       exit(0);
    }
    memcpy(element,v.element,dim*sizeof(float));
    return *this;
}

template <class T> int vecteur<T>::getdim() {return dim;}

template <class T> vecteur<T> & vecteur<T>::operator += (const vecteur & v)
{
    if(dim!=v.dim)
    {
        cout << "Dimension non identique \n";
        exit(0);
    }
    else
    {
        for(int i=0;i<dim;i++) {element[i]+=v.element[i];}
        return *this;
    }
}

template <class T> vecteur<T> operator + (vecteur<T> & v1, vecteur<T> & v2)
{
    vecteur<T> temp(v1);
    temp+=v2;
    return temp;
}

template <class T> ostream& operator << (ostream& os, vecteur<T> & v)
{
    for (int i=0;i<v.getdim();i++) {os << v[i] << ' ';}
    os << "\n";
    return(os);
}

template <class T> istream& operator >> (istream& is, vecteur<T> & v)
{
    for (int i=0;i<v.getdim();i++) {is >> v[i];}
    return(is);
}

int main()
{
    // Question 1
    vecteur<char> v1(10);
    v1.afficher();
    cout << endl << "Regardons désormais si l'opérateur [] marche bien." << endl;
    v1[3]='(';
    char f;
    f=v1[3];
    cout << "v2 vaut désormais" << endl;
    v1.afficher();
    cout << endl << "De plus, f vaut : " << f << endl << endl << endl;
    
    // Question 2
    vecteur<char> v2(3),v3(3);
    v2[0]='a';
    v2[1]='b';
    v2[2]='c';
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
    char c[3];
    c[0]='r';
    c[1]='r';
    c[2]='t';
    vecteur<char> v4(3,c);
    cout << "v3 vaut : ";
    v3.afficher();
    cout << endl;
    cout << "v4 vaut : ";
    v4.afficher();
    cout << endl << endl;
    
    vecteur<char> v5(3);
    v5=operator + (v3,v4);
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

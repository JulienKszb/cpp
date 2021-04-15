#include "TP2.hpp"

#include <vector>
#include <iostream>
#include <list>
#include <set>
#include <map>
using namespace std;




int main()
{
    cout << endl << "Exercice 1 :" << endl <<endl;
    vector<float> v1;
    
    for(int i=0;i<10;i++) {v1.push_back((float)i/10);}
    
    vector<float> v2;
    v2=v1;
    for(int i=0;i<(int) v2.size()/2+1;i++) {v2.pop_back();}
    
    vector<float>::iterator it1;
    for(it1=v1.begin();it1!=v1.end();it1++) {cout << *it1 << " ";}
    
    cout << endl;
    
    vector<float>::iterator it2;
    for(it2=v2.begin();it2!=v2.end();it2++) {
        cout << *it2 << " ";
    }
    cout << endl << endl << endl << endl;
    
    cout << endl << "Exercice 2 :" << endl << endl;
    list<char> l1,l2;
    list<char>::iterator it3,it4;
    for(int i=0;i<10;i++) {
        l1.push_back(65+i);
    }
    for(it3=l1.begin();it3!=l1.end();it3++) {
        cout << *it3 << " ";
    }
    cout << endl;
    l2=l1;
    for(int i=0;i<(int) l2.size()/2 +1;i++) {
        l2.pop_front();
    }
    
    for(it4=l2.begin();it4!=l2.end();it4++) {cout << *it4 << " ";}
    
    cout << endl << endl << endl << endl;
    
    cout << endl << "Exercice 3 :" << endl << endl;
    
    set<string> s1;
    set<string>::iterator it5,it6;
    s1.insert("Pierre");
    s1.insert("Paul");
    s1.insert("Emilien");
    s1.insert("Emile");
    s1.insert("Nathalie");
    s1.insert("Jane");
    s1.insert("Emma");
    s1.insert("Manon");
    
    for(it5=s1.begin();it5!=s1.end();it5++) {cout << *it5 << " ";}
    
    cout << endl;
    it5=s1.begin();
    it6=it5;
    
    for(int i=0;i<2;i++,it6++) {}
    s1.erase(it5,it6);
    
    for(it5=s1.begin();it5!=s1.end();it5++) {cout << *it5 << " ";}
    
    cout << endl << endl << endl << endl;
    
    cout << endl << "Exercice 4 :" << endl << endl;
    
    map<string,int> m1;
    map<string,int>::iterator it7;
    m1["Louise"]=3535;
    m1["Alexis"]=4000;
    m1["Philomène"]=2000;
    m1["Mathieu"]=1400;
    m1["Marine"]=5000;
    m1["Léonie"]=3300;
    m1["Michel"]=1000;
    m1["Julien"]=5200;
    
    for(it7=m1.begin();it7!=m1.end();it7++) {
        cout << it7->first << "    " << it7->second <<endl;
    }
    
    cout << endl << endl;
    for(it7=m1.begin();it7!=m1.end();) {
        if ( (int) it7->second/1000==5 )
        {
            it7=m1.erase(it7);
        }
        else it7++;
    }
    
    for(it7=m1.begin();it7!=m1.end();it7++) {
        cout << it7->first << "    " << it7->second <<endl;
    }
    
    cout << endl << endl << endl << endl;
    
    cout << endl << "Exercice 5 :" << endl << endl;
    
    vector<string> vect;
    vector<string>::iterator it8;
    vect.push_back("Coucou");
    vect.push_back("je ne sais pas quoi dire");
    vect.push_back("Ssss mais je remplis ce texte");
    vect.push_back("Anojnzeofhoia");
    vect.push_back("voilà.");
    
    for(it8=vect.begin();it8!=vect.end();it8++) {cout << *it8 << endl;}
    
    cout << endl;
    
    sort(vect.begin(),vect.end());
    
    for(it8=vect.begin();it8!=vect.end();it8++) {cout << *it8 << endl;}
    
    cout << endl << endl << endl << endl;
    
    cout << endl << "Exercice 6 :" << endl << endl;
    
    list<string> phrase;
    list<string>::iterator it9;
    
    phrase.push_back("Il");
    phrase.push_back("fait");
    phrase.push_back("beau");
    
    for(it9=phrase.begin();it9!=phrase.end();it9++) {cout << *it9 << " ";}
    
    cout<< endl;
    
    it9=find(phrase.begin(),phrase.end(),"beau");
    phrase.insert(it9,"très");
    
    for(it9=phrase.begin();it9!=phrase.end();it9++) {cout << *it9 << " ";}
    

    
    
    
    
    
    
    
    return 0;
}

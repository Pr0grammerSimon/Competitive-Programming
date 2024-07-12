/*
Rozwiazanie polega na symulowaniu powstawania drzewa, dopoki nasza glebokosc jest za mala to schodzimy w dol (lewy syn),
jezeli jestesmy na odpowiednim poziomie to stawiamy syna, gdy wrocimy z rekurencji z lewego syna a w prawo nie mozemy isc 
bo aktualna szukana glebokosc jest mniejsza niz my to wiemy ze nie bedzie juz to drzewo binarne 
(bo postawilismy w lewym synie wierzcholek, a w drugiem nie ), wiec odpowiedz bedzie "NIE", rowniez gdy skonczymy
symulowanie powstawania drzewa a okaze sie ze nie wszystkie glebokosci zostaly "umieszczone" tak jak na wejsciu,
to odpowiedz to rowniez "NIE"

*/



#include <bits/stdc++.h>

using namespace std;

string napis="(";
string rodzice="0 ";
int akt_pre=1;

const int MAXN = 2500;
int poziomy[MAXN];
int akt_poziom=0;
int n;
int poprawne = 1;

void dfs(int glebokosc){
    int pre_v = akt_pre;
    akt_pre++;
    int lewy=0;
    

    if (akt_poziom==n) return;
    if (glebokosc == poziomy[akt_poziom]){
        akt_poziom++;
        return;
    }
    if (glebokosc < poziomy[akt_poziom]){
        napis += "(";
        rodzice+=to_string(pre_v)+" ";
        dfs(glebokosc+1);
        napis += ")";
        lewy=1;
    }
    
    if (glebokosc < poziomy[akt_poziom]){
        napis += "(";
        rodzice+=to_string(pre_v)+" ";
        dfs(glebokosc+1);
        napis += ")";
    }
    else if (lewy) poprawne=0;
}


int main(){

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> poziomy[i];
    }
    
    
    
    dfs(0);
    napis += ")";
    
    if (akt_poziom==n && poprawne)
    cout << rodzice << '\n' << napis << '\n';
    else
    cout << "NIE\n";
    
    return 0;
}
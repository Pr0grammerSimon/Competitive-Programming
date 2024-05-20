#include "combo.h"
#include <string>
using namespace std;
 
string guess_sequence(int N){
    int k;
    char literka;
    string wynik="",query;
    if (press("AB")){
        if (press("A")){
            literka = 'A';
        }
        else{
            literka = 'B';
        }
    }
    else{
        if (press("X")){
            literka = 'X';
        }
        else{
            literka = 'Y';
        }
    }
    wynik += literka;
    
    string li_1="",li_2="",li_3="";
    for (auto i: "ABXY"){
        if (i==literka) continue;
        if(li_1=="") li_1 = i;
        else if (li_2=="") li_2 = i;
        else if (li_3=="") li_3 = i;
    }
    
    for (int i=2; i<N; i++){
        query = wynik+li_1+wynik+li_2+li_1+wynik+li_2+li_2+wynik+li_2+li_3;
        k = press(query);
        if (k-i+1 == 1){
            wynik += li_1;
        }
        else if(k-i+1 == 2){
            wynik += li_2;
        }
        else wynik += li_3;
    }
    
    if (N!=1){
        if (press(wynik+"A"+wynik+"B")==N){
            if (press(wynik+"A")==N){
                literka = 'A';
            }
            else{
                literka = 'B';
            }
        }
        else{
            if (press(wynik+"X")==N){
                literka = 'X';
            }
            else{
                literka = 'Y';
            }
        }
        wynik += literka;
    }
    
    return wynik;
}
 
#include <bits/stdc++.h>
using namespace std;

int j,n;
string wzorzec,litery;


bool check(int mid){
    int akt_ilosc=0,akt_litera_2=0;
    char akt_litera=wzorzec[0];

    for (auto litera:litery){
        if (litera==akt_litera){
            akt_ilosc++;
            if (akt_ilosc==mid){
                akt_ilosc=0;
                akt_litera_2++;
                if (akt_litera_2==j) return true;
                akt_litera=wzorzec[akt_litera_2];
            }
        }
    }
    return false;
}

int bins(){
    int left=1,right=200000,mid;
    while (left<right){
        mid = (left+right) >> 2;
        if (check(mid)) left = mid;
        else right = mid-1;
    }
    
}
int main(){

    cin >> j >> n;

    cin >> wzorzec;
    cin >> litery;
    cout << bins()*j<<endl;
}
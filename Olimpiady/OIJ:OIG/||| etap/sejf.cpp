#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long wynik;
    int rozmiar,ilosc_zapytan,a,b;
    char typ;
    cin >> rozmiar >> ilosc_zapytan;
    int kolumny[rozmiar+7];
    int wiersze[rozmiar+7];
    for (int i=0; i<rozmiar+8; i++){
        kolumny[i] = i;
        wiersze[i] = i;
    }
    for (int i=0; i<ilosc_zapytan; i++){
        cin >> typ >> a >> b;
        if (typ == 'W'){
            swap(wiersze[a],wiersze[b]);
        }
        else if (typ == 'K'){
            swap(kolumny[a],kolumny[b]);
        }
        else{
            wynik = ( (long long)rozmiar*(wiersze[a] - 1) + kolumny[b] );
            cout<<wynik<<endl;
        }
    }

    return 0;
}
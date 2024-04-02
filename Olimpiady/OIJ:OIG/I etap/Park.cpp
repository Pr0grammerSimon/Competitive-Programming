#include <bits/stdc++.h>
using namespace std;

int ilosc_podzialow;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> ilosc_podzialow;
    long long podzialy[ ilosc_podzialow ];
    long long lewo[ ilosc_podzialow ];
    long long prawo[ ilosc_podzialow ];
    long long maksi;
    maksi = 0;
    for (int i=0; i<ilosc_podzialow; i++){
        cin>>podzialy[i];
        maksi = max(maksi,podzialy[i]);
        lewo[i] = maksi;
    }
    maksi = 0;
    for (int i=ilosc_podzialow-1; i>=0; i--){
        maksi = max(maksi,podzialy[i]);
        prawo[i] = maksi;
    }
    
    for (int i=0; i<ilosc_podzialow; i++){
        cout << lewo[i] << " " << prawo[i] << endl;
    }
    
    
}
#include <bits/stdc++.h>

using namespace std;
unsigned long long akt_ilosc[200007];

int main(){
    akt_ilosc[0] = 1;
    unsigned long long n,k,akt;
    const unsigned long long MOD = 1e9+9;
    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> akt;
        akt_ilosc[akt] = (unsigned long long)( (unsigned long long)(akt_ilosc[akt])%MOD + (unsigned long long)(akt_ilosc[akt-1])%MOD )%MOD;
    }
    cout << (unsigned long long)((unsigned long long)(akt_ilosc[k])%(unsigned long long)(MOD));

    return 0;
}


#include <iostream>

using namespace std;
long long ilosc_temperatur;
long long n = 1048576;
long long drzewo[ 1048576*2 ];
long long a;
long long b;

long long query(long long left, long long right){
    long long l = left-1+n;
    long long r = right+1+n;
    long long wynik_2 = -1e9+7;
    while (l/2 != r/2){
        if (l%2==0) wynik_2 = max(wynik_2,drzewo[l+1]);
        if (r%2==1) wynik_2 = max(wynik_2, drzewo[r-1]);
        r/=2;
        l/=2;
    }
    return wynik_2;
}


void edit(long long p, long long value){
    long long poz = p+n;
    drzewo[poz] = value;
    poz/=2;
    while (poz>0){
        drzewo[poz] = max(drzewo[poz*2],drzewo[poz*2+1]);
        poz/=2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> ilosc_temperatur; 
    long long temperatury[ilosc_temperatur];
    for (long long i = 0; i<ilosc_temperatur; i++){
        cin >> a;
        cin >> b;
        temperatury[i] = b;
        edit(i,a);
    }
    long long right = 0;
    long long wynik = -1e9+7;
    for (long long i = 0; i<ilosc_temperatur;i++){
        while (right < ilosc_temperatur and query(i,right-1) <= temperatury[right]){
            right ++;
            wynik = max(wynik,right-i);
        }
    }
    cout << wynik;
    return 0;
}

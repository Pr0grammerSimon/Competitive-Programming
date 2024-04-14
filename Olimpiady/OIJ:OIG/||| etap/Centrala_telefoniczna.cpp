#include <bits/stdc++.h>

using namespace std;

long double odleglosc(int y,int x){
    return sqrt(pow(y,2)+pow(x,2));
}
long long koszt(int h){
    return (h-1)*h/2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    priority_queue < pair <double, long long> > kolejka;
    long long ilosc_domow,zwiekszanie,ilosc_wierzcholkow,zaplata,x,y,wynik=0,zysk=0,wysokosc;
    long double maksi;
    pair <long double,long long> punkt;
    cin >> ilosc_domow >> zwiekszanie;
    for (int i=0; i<ilosc_domow; i++){
        maksi = (double)0;
        cin >> ilosc_wierzcholkow >> zaplata;
        for (int i=0; i<ilosc_wierzcholkow*2; i+=2){
            cin >> x >> y;
            maksi = max(maksi,(long double)odleglosc(y,x));
        }
        kolejka.push({-maksi,zaplata});
    }
    
    for (int i=0; i<ilosc_domow; i++){
        punkt = kolejka.top();
        kolejka.pop();
        zysk += punkt.second;
        wysokosc = ceil((punkt.first*-1)/zwiekszanie);
        wynik = max(wynik,zysk-koszt(wysokosc));
    }
    cout << wynik;
    return 0;
}


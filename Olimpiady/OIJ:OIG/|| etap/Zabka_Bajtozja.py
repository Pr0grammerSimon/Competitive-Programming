import math
liczba_kamieni,numer_kamienia,dlugosc_skoku = [int(i) for i in input().split()]
kamienie = [[] for _ in range(liczba_kamieni)]
odwiedzone = [False for _ in range(liczba_kamieni)]
wynik = 0
for i in range(liczba_kamieni):
    x,y = input().split()
    kamienie[i] = [int(y),int(x)]

#print(kamienie)
def odleglosc(y_1,x_1,y_2,x_2):
    return math.sqrt(math.pow(x_2-x_1,2)+math.pow(y_2-y_1,2))
def solution(kamien): 
    global odwiedzone,wynik
    wynik = max(wynik, odleglosc(kamienie[numer_kamienia-1][0],kamienie[numer_kamienia-1][1],kamienie[kamien][0],kamienie[kamien][1]))
    odwiedzone[kamien] = True
    for i in range(liczba_kamieni):
        if not odwiedzone[i] and odleglosc(kamienie[kamien][0],kamienie[kamien][1],kamienie[i][0],kamienie[i][1]) <= dlugosc_skoku:
            solution(i)

solution(numer_kamienia-1)
print(f"{wynik+dlugosc_skoku:.3f}")



""" C++ 100%
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;


int liczba_kamieni,numer_kamienia,dlugosc_skoku,w,h,MAXN=1007;
int y[ 1007 ], x[ 1007 ];
bool odwiedzone[ 1007 ];
long double wynik=0;

long double odleglosc(int y_1,int x_1,int y_2,int x_2){
    return sqrt(pow(x_2-x_1,2)+pow(y_2-y_1,2));
}

void solution(int kamien){
    wynik = max(wynik, odleglosc(y[numer_kamienia-1],x[numer_kamienia-1],y[kamien],x[kamien]));
    odwiedzone[kamien] = 1;
    for (int i=0; i<liczba_kamieni; i++){
        if (not odwiedzone[i] and odleglosc(y[kamien],x[kamien],y[i],x[i]) <= dlugosc_skoku)
            solution(i);
    }
}

int main()
{
    cin >> liczba_kamieni >> numer_kamienia >> dlugosc_skoku;
    for (int i=0; i<liczba_kamieni; i++){
       cin >> w >> h;
       y[i] = h;
       x[i] = w;
       odwiedzone[i] = 0;
    }
    solution(numer_kamienia-1);
    cout << fixed << setprecision(3) <<(long double)wynik+dlugosc_skoku;
    return 0;
}


"""
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * (1e6+7);
pair<int,int> tablica[MAXN];
int rep[MAXN];
int val[MAXN];
int jest[MAXN];
int wynik[MAXN];
int n,q,zapytanie,w,ostatni=0;

int find(int a){
    if (rep[a] != a){
        rep[a] = find(rep[a]);
    }
    return rep[a];
}

void union_(int a, int b){
    int a_,b_;
    
    a_=find(a);
    b_=find(b);
    
    val[b_]+=val[a_];
    rep[a_]=b_;
    
}

int main()
{

    cin >> n >> q;
    
    for (int i=0; i<n; i++){
        val[i]=1;
        jest[i]=0;
    }
    
    for (int i=0; i<n; i++){
        cin >> tablica[i].first;
        tablica[i].second = i;
        rep[i] = i;
    }
    
    sort(tablica, tablica + n);
    
    
    for (int i=0; i<n; i++){
        jest[tablica[i].second]=1;
        if ((tablica[i].second+1) < n && jest[tablica[i].second+1]){
            union_(tablica[i].second,tablica[i].second+1);
        }
        if ((tablica[i].second-1) >= 0 && jest[tablica[i].second-1]){
            union_(tablica[i].second,tablica[i].second-1);
        }
        
        w = val[find(tablica[i].second)];
        
        for (int j=ostatni+1; j<=w; j++){
            wynik[j]=tablica[i].first;
        }
        
        ostatni = max(ostatni,w);
    }
    
    for (int i=0; i<q; i++){
        cin >> zapytanie;
        cout << wynik[zapytanie]<<" ";
    }
    
    
    
    

    return 0;
}
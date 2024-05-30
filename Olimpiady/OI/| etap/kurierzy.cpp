#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500007;
const int base = 1<<19;
pair<int,int> tree[base*2];

int tab[MAXN];

void edit(int val, int v){
    //cout << "EDIT"<<endl;
    v+=base;
    tree[v] = {val,1};
    v/=2;
    while (v>0){
        tree[v] = tree[v*2];
        if (tree[v*2+1].second > 0){
            if (tree[v*2+1].first==tree[v].first) tree[v].second += tree[v*2+1].second;
            else{
                if (tree[v*2+1].second > tree[v].second){
                    tree[v] = tree[v*2+1];
                    tree[v].second -= tree[v*2].second;
                }
                else{
                    tree[v].second -= tree[v*2+1].second;
                }
            }
        }
        if (tree[v].second == 0) tree[v] = {-1,0};
        //cout << tree[v].first << " " << tree[v].second << endl;
        v/=2;
    }
}

pair<int,int> kandydat(int left, int right){
    //cout << "WEJSCIE kandydat"<<endl;
    left += base-1;
    right += base+1;
    pair<int,int> wynik;
    pair<int,int> wynik2;
    while (left/2 != right/2){
        if (left%2==0){ 
            if (tree[left+1].first==wynik.first) wynik.second += tree[left+1].second;
            else{
                if (wynik.second < tree[left+1].second){
                    wynik2 = wynik;
                    wynik = tree[left+1];
                    wynik.second -= wynik2.second;
                }
                else{
                    wynik.second -= tree[left+1].second;
                }
            }
            if (wynik.second == 0) wynik = {-1,0};
        }
        if (right%2==1){
            if (tree[right-1].first==wynik.first) wynik.second += tree[right-1].second;
            else{
                if (wynik.second < tree[right-1].second){
                    wynik2 = wynik;
                    wynik = tree[right-1];
                    wynik.second -= wynik2.second;
                }
                else{
                    wynik.second -= tree[right-1].second;
                }
            }
            if (wynik.second == 0) wynik = {-1,0};
        }
        left/=2;
        right/=2;
        //cout << wynik.first<<endl;
    }
    return wynik;

}


int main(){
    int n,q,akt,a,b,w;
    pair<int , int> info;
    cin >> n >> q;
    for (int i=0; i<n; i++){
        cin >> tab[i];
        edit(tab[i],i);
    }
    
    int wyniki[MAXN]; // wyniki dla zapytan
    vector<vector<int>> poczatek(n,vector<int>()); // idx zapytania 
    vector<vector<pair<int,int>>> koniec(n,vector<pair<int,int>>());//jakie sie koncza na danym punkcie i dlugosc
    vector<pair<int,int>> zapytania(q); // kandydat i ilosc na poczatek
    vector<int> akt_ilosc(n+1);
    
    
    for (int i=0; i<q; i++){
        cin >> a >> b;
        a--; b--;
        info = kandydat(a,b);
        poczatek[a].push_back(i);
        koniec[b].push_back({i,b-a+1});
        zapytania[i] = {info.first,0};
    }
    
    for (int i=0; i<n; i++){
        for (auto idx : poczatek[i]){
            zapytania[idx].second = akt_ilosc[zapytania[idx].first];
        }
        akt_ilosc[tab[i]] += 1;
        for (auto [end,dlugosc] : koniec[i]){
            w = akt_ilosc[zapytania[end].first]-zapytania[end].second;
            if (w>dlugosc/2) wyniki[end] = zapytania[end].first;
            else wyniki[end] = 0;
        }
    }
    for (int i=0; i<q; i++) cout << wyniki[i] << endl;

}
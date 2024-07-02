#include <bits/stdc++.h>

using namespace std;

const int MAXX = 1e6+3;
int sito[MAXX];
int ile_dzielnik[MAXX];
int pomocnicza;
int wyniki[MAXX];

int akt_dzielnik,ile;

vector<pair<int,int>> graf[MAXX];


void dfs(int v, int xor_, int liczba){
    
    
    
    akt_dzielnik = sito[liczba];
    ile = 0;
    pomocnicza = liczba;
    while (pomocnicza > 1){
        if (akt_dzielnik != sito[pomocnicza]){
            
            xor_ ^= ile_dzielnik[akt_dzielnik];
            xor_ ^= (ile+ile_dzielnik[akt_dzielnik]);
           
            ile_dzielnik[akt_dzielnik] += ile;
            akt_dzielnik = sito[pomocnicza];
            ile = 0;
        }
        ile ++;
        pomocnicza/=sito[pomocnicza];
    }
  
    if (akt_dzielnik != 0){
        xor_ ^= ile_dzielnik[akt_dzielnik];
        xor_ ^= (ile+ile_dzielnik[akt_dzielnik]);
      
        ile_dzielnik[akt_dzielnik] += ile;
    }

    
    wyniki[v] = xor_;
    for (auto [idx,liczba_2] : graf[v]){
        dfs(idx, xor_, liczba_2);
    }
    
    
    
    akt_dzielnik = sito[liczba];
    ile = 0;
    
    pomocnicza = liczba;
    
    while (pomocnicza > 1){
        
        if (akt_dzielnik != sito[pomocnicza]){
            ile_dzielnik[akt_dzielnik] -= ile;
            akt_dzielnik = sito[pomocnicza];
            ile = 0;
        }
        ile ++;
        pomocnicza/=sito[pomocnicza];
    }
    if (akt_dzielnik != 0){
        
        ile_dzielnik[akt_dzielnik] -= ile;
    }
    
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    for (int i=0; i<MAXX; i++) sito[i] = i;
    
    int sqrt_ = sqrt(MAXX)+1;
    for(int i=2; i<sqrt_; i++){
        if (sito[i]!=i) continue;
        for (int j=i*i; j<=MAXX-1; j+=i){

            if (sito[j]==j) sito[j]=i;
        }
    }
    
    int n,liczba,idx,wynik;
    cin >> n;
    
    
    
    for (int i=1; i<=n; i++){
        cin >> idx >> liczba;
        
        graf[idx].push_back({i,liczba});
    }
    

    dfs(0, 0, 0);    
    

    for (int i=1; i<=n; i++){
        if (wyniki[i]!=0) cout<<"Alicja"<<endl;
        else cout << "Bob" <<endl;
    }
    
}
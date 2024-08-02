//W rozwiązaniu będziemy sprawdzać kazde k od 1 do n oraz mamy 4 hashe 
//Hashe: (mod 1 - normalny, mod 1 - od tylu, mod 2 - normalny, mod 2 - od tylu). 
//Sprawdzenie dla danego k wygląda następująco:
//1. Trzymamy 2 sety w ktorej bedziemy trzymac hashe z 1 i 2 modulo
//Przechodzimy sie po kolei po kazdym sznurze i jezeli dla kazdego modulo normalny hash i odwrocony jeszcze nie jest w jego secie, 
//to zwiekszamy jaki bylby otrzymany wynik dla danego k i dodajemy do setow odwrocony hash i normalny do danego modulo 
//Trzymamy dodatkowo mape ktora dla danego wyniku powie jakie wartosci k je mialy
//Wiec gdy otrzymamy nasz koncowy maksymalny wynik, wystarczy nam odczytac z mapy poszczegolne wartosci


#include <bits/stdc++.h>

using namespace std;

const int POW = 200009;
const int MOD = 1e9+9;
const int MOD2 = 1e9+7;
const int MAXN = 200007;

int n;
long long tablica_p[MAXN+1];
long long tablica_p_2[MAXN+1];
int tablica[MAXN];
vector<int> hash_1;
vector<int> hash_2;

vector<int> o_hash_1;
vector<int> o_hash_2;


int h_1,h_2,oh_1,oh_2;

 

void get_hash(int a, int b){
    
    long long hsh_1,hsh_2;
    
    if (a > 0) {hsh_1 = (hash_1[b]-hash_1[a-1]+MOD)%MOD; hsh_2=(hash_2[b]-hash_2[a-1]+MOD2)%MOD2;}
    else {hsh_1 = hash_1[b]; hsh_2=hash_2[b];}
    
    
    h_1 = (hsh_1*tablica_p[MAXN-a])%MOD;
    h_2 = (hsh_2*tablica_p_2[MAXN-a])%MOD2;
    
    
    int b_=b,a_=a;
    a = (n-b_-1);
    b = (a+(b_-a_));
    
    if (a > 0) {hsh_1 = (o_hash_1[b]-o_hash_1[a-1]+MOD)%MOD; hsh_2=(o_hash_2[b]-o_hash_2[a-1]+MOD2)%MOD2;}
    else {hsh_1 = o_hash_1[b]; hsh_2=o_hash_2[b];}
    
    
    oh_1 = (hsh_1*tablica_p[MAXN-a])%MOD;
    oh_2 = (hsh_2*tablica_p_2[MAXN-a])%MOD2;
    
    
    
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    
    int literka;
    
    tablica_p[0] = 1;
    tablica_p_2[0] = 1;
    for (int i=1; i<MAXN+1; i++){
        tablica_p[i] = (tablica_p[i-1]*POW)%MOD;
        tablica_p_2[i] = (tablica_p_2[i-1]*POW)%MOD2;
    }

    long long akt_suma_1=0;
    long long akt_suma_2=0;
    
    for (int i=0; i<n; i++){
        cin >> tablica[i];
        literka = tablica[i];
        
        akt_suma_1 = (akt_suma_1 + (literka*tablica_p[i]) % MOD ) % MOD;
        hash_1.push_back(akt_suma_1);
        
        akt_suma_2 = (akt_suma_2 + (literka*tablica_p_2[i]) % MOD2 ) % MOD2;
        hash_2.push_back(akt_suma_2);

    }

    akt_suma_1=0;
    akt_suma_2=0;
    int j=0;
    for (int i=n-1; i>=0; i--){
        literka = tablica[i];

        akt_suma_1 = (akt_suma_1 + (literka*tablica_p[j]) % MOD ) % MOD;
        o_hash_1.push_back(akt_suma_1);
        
        akt_suma_2 = (akt_suma_2 + (literka*tablica_p_2[j]) % MOD2 ) % MOD2;
        o_hash_2.push_back(akt_suma_2);
        j++;
    }
    
    int maxi=0;
    map<int,vector<int>> wyniki;

    
    for (int i=1; i<=n; i++){
        set<int> secik_1;
        set<int> secik_2;
        int akt_wynik=0;
        for (int j=0; j<=(n-i); j+=i){
            get_hash(j,j+i-1);

            if (secik_1.find(h_1)==secik_1.end() && secik_1.find(oh_1)==secik_1.end() && secik_2.find(h_2)==secik_2.end()&&secik_2.find(oh_2)==secik_2.end()){
                secik_1.insert(h_1);
                secik_1.insert(oh_1);
                secik_2.insert(h_2);
                secik_2.insert(oh_2);
                akt_wynik++;
            }

        }
        
        maxi = max(maxi,akt_wynik);
        
        if (wyniki.find(akt_wynik)!=wyniki.end()) wyniki[akt_wynik].push_back(i);
        else wyniki[akt_wynik] = {i};
        
    }

    cout << maxi << " " << wyniki[maxi].size() << endl;
    for (auto i : wyniki[maxi]) cout<<i<<" ";

    
    return 0;
}
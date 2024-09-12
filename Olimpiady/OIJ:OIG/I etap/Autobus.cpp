#include <bits/stdc++.h>

using namespace std;

const int MAXN = 51;


int wspolrzedne[MAXN][2];

struct ulica{
    int a,b,val,idx;
};


bool sort_func(ulica &a, ulica &b){
    return a.a < b.a;
}


bool moze_przejechac(int a,int b, int c){
    
    
    
    long long x_1 = wspolrzedne[a][0]-wspolrzedne[b][0];
    long long x_2 = wspolrzedne[c][0]-wspolrzedne[b][0];
    
    long long y_1 = wspolrzedne[a][1]-wspolrzedne[b][1];
    long long y_2 = wspolrzedne[c][1]-wspolrzedne[b][1];
    
    
    long double skalarny = x_1*x_2 + y_1*y_2;
    
    
    
    if (skalarny>0) return false;
    
    
    return true;
    
    
    
    
    
}


int main()
{
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n,m,k;
    
    
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        cin >> wspolrzedne[i][0] >> wspolrzedne[i][1];
    }
    
    vector<ulica> ulice(1); //wierzcholek a b ktory ma koszt v i ma index idx

    
    vector<vector<ulica>> graf(m+1);
    
    
    int a,b,val;
    
    for (int i=1; i<=m; i++){
        cin >> a >> b >> val;
        ulica ulica_2;
        ulica_2.a = a;
        ulica_2.b = b;
        ulica_2.val = val;
        ulica_2.idx = i;
        ulice.push_back(ulica_2);
    }
    
    
    
    for (int i=1; i<=m; i++){
 
        ulica u = ulice[i];
        for (int j=1; j<=m; j++){
            ulica u_2 = ulice[j];
            if (u.b==u_2.a && u_2.idx!=u.idx && moze_przejechac(u.a,u.b,u_2.b)){
                graf[u.idx].push_back(u_2);
            }
        }
        

    }
    
    int v__,akt_koszt=0;
    
    vector<int> wyniki;
    vector<int> kolejnosc;
    
    for (int i=0; i<k; i++){
        cin >> v__;
        kolejnosc.push_back(v__);
    }
    
    
    for (int i=0; i<k-1; i++){
        
        ulica v_;
        v_ = ulice[kolejnosc[i]];
        
        vector<int> koszt(m+1,1e8);

    
        priority_queue<pair<int,int>> kolejka;
        
        
        for (ulica u : graf[v_.idx]){
            kolejka.push({-(v_.val),u.idx});
        }
        
        
        
        while (!kolejka.empty()){
            
            int v = kolejka.top().second;
            int val = -kolejka.top().first;
            
            //cout << "Wyciagam: " << v << " " << val << endl;
            kolejka.pop();
            
            if (koszt[v]<=val) continue;
            koszt[v] = val;
            
            for (ulica u : graf[v]){
        
                if (koszt[u.idx] > (val+(2*ulice[v].val))){
                    kolejka.push({-(val+(2*ulice[v].val)),u.idx});
                }
            }
            
        }
        
        if (koszt[kolejnosc[i+1]]==1e8){
            cout << "NIE\n";
            return 0;
        }
        
        akt_koszt+=koszt[kolejnosc[i+1]]+ulice[kolejnosc[i+1]].val;
        wyniki.push_back(akt_koszt);
        
        
    }
    
    for (auto w : wyniki) cout << w << endl;
   
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long parzyste[200007], nie_parzyste[200007];
const long long MAXN = 1e10+7;
int main()
{
    int ilosc_wierzcholkow,ilosc_drog,a,b,val;
    bool parzysta;
    cin >> ilosc_wierzcholkow >> ilosc_drog;
    vector<vector<pair<int,int>>> graf(ilosc_wierzcholkow+1, vector<pair<int,int>>(0));
    priority_queue<pair<int,int>> kolejka;
    for (int i=0; i<=ilosc_wierzcholkow; i++){
        parzyste[i] = MAXN;
        nie_parzyste[i] = MAXN;
    }
    for (int i=0; i<ilosc_drog; i++){
        cin >> a >> b >> val;
        graf[a].push_back({b,val});
        graf[b].push_back({a,val});
    }
    kolejka.push({-0,1});
    while (!kolejka.empty()){
        val = kolejka.top().first;
        val = -val;
        a = kolejka.top().second;
        kolejka.pop();
        if ((val % 2) == 0) {
            if (parzyste[a] <= val) continue;
            else parzyste[a] = val;
        }
        else if (nie_parzyste[a] <= val) continue;
        else nie_parzyste[a] = val;
        
        for (auto& [b,val_2] : graf[a]){
            kolejka.push({-(val+val_2),b});
        }
    }
    if (nie_parzyste[ilosc_wierzcholkow] == MAXN) nie_parzyste[ilosc_wierzcholkow] = 0;
    cout << nie_parzyste[ilosc_wierzcholkow];
    

    return 0;
}
//OD DZISIAJ BĘDĘ DODAWAŁ KOMENTARZE JEJ ;)
//POMYSŁ:
// Obliczamy minimalny koszt przemiany z złota na kazdy inny surowiec oraz z kazdego innego surowca na zloto 
//(bo trzeba potem przemienic po granicy), za pomocą dijkstry, a na koncu liczymy minimum ( Wynikiem dla danego metalu będzie koszt do granicy + z granicy + koszt cła danego metalu ;)) 
#include <bits/stdc++.h>

using namespace std;
long long metale[5007];
long long wyniki_1[5007]; //Wyniki dla Dijkstry od 1 do innych
long long wyniki_2[5007]; //Wyniki dla Dijkstry od innych do 1
long long INF = 1e12;

//Dijkstra (WOW) xd
void dijkstra(vector<vector<pair<int,int>>> graf, long long wyniki[5007]){
    priority_queue<pair<int,int>> kolejka;
    kolejka.push({-0,0});
    int value,v;
    while (! kolejka.empty()){
        value = -kolejka.top().first;
        v = kolejka.top().second;
        kolejka.pop();
        if (value < wyniki[v]) wyniki[v] = value;
        else continue;
        for (auto [b,val] : graf[v]){
            kolejka.push({-(value+val),b});
        }
    }
}

int main(){
    int ilosc_metali,ilosc_przemian,a,b,val;
    cin >> ilosc_metali;
    
    for (int i=0; i<ilosc_metali; i++){
        cin >> metale[i];
        metale[i]/=2; // Cło tylko 50%
        //Przygotowanie dla Dijkstry
        wyniki_1[i] = INF;
        wyniki_2[i] = INF;
    }
    vector<vector<pair<int,int>>> graf(ilosc_metali,vector<pair<int,int>>(0));
    vector<vector<pair<int,int>>> graf2(ilosc_metali,vector<pair<int,int>>(0));
    cin >> ilosc_przemian;
    for (int i=0; i<ilosc_przemian; i++){
        cin >> a >> b >> val;
        graf[a-1].push_back({b-1,val});
        graf2[b-1].push_back({a-1,val}); // Odwrocony graf dla dijkstry z innych do złota
    }
    dijkstra(graf,wyniki_1);// Wyniki dla złota do innych (do granicy)
    dijkstra(graf2,wyniki_2);// Wyniki dla innych do złota (po granicy)
    long long wynik = INF;
    for (int i=0; i<ilosc_metali; i++){
        wynik = min(wyniki_1[i]+wyniki_2[i]+metale[i],wynik); // Wynikiem dla danego metalu będzie koszt do granicy + z granicy + koszt cła danego metalu ;)
    }
    cout << wynik;
    
}
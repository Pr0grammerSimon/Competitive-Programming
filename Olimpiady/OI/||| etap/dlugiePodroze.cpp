#include <iostream>
#include <set>
#include <queue>


using namespace std;

const int MAXN = 100001;
int odleglosci[230][MAXN];
vector<int> graf[MAXN];


void bfs(int v, int nmb){

    queue<int> kolejka;
    vector<bool> odw(MAXN + 1, false);

    kolejka.push(v);
    odw[v] = true;

    while (!kolejka.empty()){
        int v_2 = kolejka.front();
        kolejka.pop();
        for (int sasiad : graf[v_2]){
            if (!odw[sasiad]){
                kolejka.push(sasiad);
                odw[sasiad] = true;
                odleglosci[nmb][sasiad] = odleglosci[nmb][v_2] + 1;
            }
        }
    }

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    srand(time(NULL));


    int n, m, p;

    cin >> n >> m >> p;


    int a, b;

    while (m--){
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }

    set<int> wierzcholki_wylosowane;

    while (wierzcholki_wylosowane.size() < min(n, 230)){
        int v = rand() % n + 1;
        wierzcholki_wylosowane.insert(v);
    }

    int i = 0;

    for (int val : wierzcholki_wylosowane){
        bfs(val, i);
        i++;
    }

    for (int i=0; i<p; i++){
        cin >> a >> b;

        int wynik = 100000000;
        for (int j=0; j < wierzcholki_wylosowane.size(); j++){
            wynik = min(wynik, odleglosci[j][a] + odleglosci[j][b]);
        }

        cout << wynik << endl;
    }


    return 0;
}
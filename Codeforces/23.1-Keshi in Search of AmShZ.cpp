#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;


const int MAXN = 2e5 + 7;
vector<int> graf[MAXN];
int liczba[MAXN];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    int n, m, a , b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graf[b].push_back(a);
        liczba[a] ++;
    }

    priority_queue<pii, vector<pii>, greater<pii>> kolejka;
    vector<int> wynik(n + 1, 1e9);
    
    wynik[n] = 0;
    kolejka.push({0, n});

    while (!kolejka.empty()) {
        int time = kolejka.top().first;
        int v = kolejka.top().second;
        kolejka.pop();

        if (wynik[v] < time) continue;

        for (int s : graf[v]) {
            int new_time = wynik[v] + liczba[s]--;
            if (new_time < wynik[s]) {
                wynik[s] = new_time;
                kolejka.push({wynik[s], s});
            }
        }
    }

    cout << wynik[1] << '\n';

    return 0;
}
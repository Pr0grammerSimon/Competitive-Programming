#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using vi = vector<int>;


const int MAXN = 2e5 + 7;
vi graf[MAXN];
vi graf2[MAXN];
int odl1[MAXN];
bool odw[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graf[a].push_back(b);
        graf2[b].push_back(a);
    }

    queue<int> kolejka_bfs;
    kolejka_bfs.push(0);
    odl1[0] = 0; 
    odw[0] = 1;

    while (!kolejka_bfs.empty()) {
        int v = kolejka_bfs.front();
        kolejka_bfs.pop();

        for (int s : graf[v]) {
            if (!odw[s]) {
                kolejka_bfs.push(s);
                odl1[s] = odl1[v] + 1;
                odw[s] = 1;
            }
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> kolejka;
    kolejka.push({0, n - 1});

    vector<int> odp(n, 1e9);
    odp[n - 1] = 0;

    while (!kolejka.empty()) {
        int odl = kolejka.top().first;
        int v = kolejka.top().second;
        kolejka.pop();

        if (odl > odp[v]) continue;
        

        for (int s : graf2[v]) {
            int new_odl = max(odl1[s], odl + 1);
            if (new_odl < odp[s]) {
                odp[s] = new_odl;
                kolejka.push({odp[s], s});
            }
        }

    }

    for (int i = 0; i < n - 1; i++) cout << odp[i] << ' ';


    return 0;
}
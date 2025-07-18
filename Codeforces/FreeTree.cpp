#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<vector<pii>> graph;
vector<int> parent;
vector<int> cost_parent;
vector<int> color;
vector<map<int, ll>> maps;


ll score = 0;

void dfs(int v, int p) {
    for (auto & [s, cost] : graph[v]) {
        if (s != p) {
            parent[s] = v;
            cost_parent[s] = cost;
            maps[v][color[s]] += cost; 

            if (color[s] != color[v]) score += cost;
            dfs(s, v);
        }
    }
}

void solve(){
    int n, q, a, b, cost;
    cin >> n >> q;

    score = 0;
    color.assign(n, 0);
    graph.assign(n, {});
    parent.assign(n, 0);
    cost_parent.assign(n, 0);
    maps.assign(n, {});


    for (int i = 0; i < n; i++) cin >> color[i];
    for (int i = 0; i < n - 1; i ++) {
        cin >> a >> b >> cost;
        a--;
        b--;
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }

    dfs(0, 0);

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        a--;
        ll act_value = maps[a][color[a]] + cost_parent[a] * (color[parent[a]] == color[a]);
        score += act_value;
        if (parent[a] != a) maps[parent[a]][color[a]] -= cost_parent[a];


        color[a] = b;
        if (parent[a] != a) maps[parent[a]][color[a]] += cost_parent[a];
        score -= maps[a][color[a]] + cost_parent[a] * (color[parent[a]] == color[a]);
        
        cout << score << '\n';
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) solve();


    return 0;
}
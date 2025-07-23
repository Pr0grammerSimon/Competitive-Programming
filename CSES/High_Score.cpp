#include <iostream>
#include <vector>


using namespace std;
using ll = long long; 
using vi = vector<int>;

const int MAXN = 2e5 + 7;

vector<pair<int, int>> graph[MAXN];
vector<int> graph2[MAXN];
bool good[MAXN];

void dfs(int v) {
    if (good[v]) return; //already visited
    good[v] = 1;

    for (int neigh : graph2[v]) {
        dfs(neigh);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, a, b, c;
    cin >> n >> m;


    vector<vector<long long>> ans(n + 1, vector<long long>(n + 1, -1e18));

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph2[b].push_back(a);
    } 

    dfs(n);

    ans[0][1] = 0;

    for (pair<int, int> & n : graph[1]) {
        ans[0][n.first] = max(ans[0][n.first], (ll)n.second);
    }


    for (int i = 1; i <= n; i++) {
        ans[i][1] = 0;
        for (int j = 1; j <= n; j++) {
            if (ans[i - 1][j] == -1e18) continue;
            for (pair<int, int> & n : graph[j]) {
                ans[i][n.first] = max(ans[i][n.first], ans[i - 1][j] + (ll)n.second);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (ans[n - 1][i] < ans[n][i] && good[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }
    
  
    cout << ans[n - 1][n] << '\n';



    return 0;
}
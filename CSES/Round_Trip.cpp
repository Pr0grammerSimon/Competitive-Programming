#include <iostream>
#include <vector>


using namespace std;
using vi = vector<int>;

const int MAXN = 2e5 + 7;

vector<int> graph[MAXN];
int vis[MAXN];
int act_turn = 0;
vector<int> dfs_stack;

void dfs(int v, int lastv) {
    if (vis[v] && vis[v] != act_turn) return;
    if (vis[v] == act_turn) {
        vector<int> ans;
        ans.push_back(v);
        while (dfs_stack.back() != v) {
            ans.push_back(dfs_stack.back());
            dfs_stack.pop_back();
        }
        ans.push_back(v);
        
        cout << ans.size() << '\n';
        for (int v : ans) cout << v << ' ';
        exit(0);
    }
    vis[v] = act_turn;
    dfs_stack.push_back(v);

    for (int s : graph[v]) {
        if (lastv != s) dfs(s, v);
    }
    dfs_stack.pop_back();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        act_turn = i;
        dfs(i, i);
        dfs_stack.clear();
    }

    cout << "IMPOSSIBLE\n";

    return 0;
}
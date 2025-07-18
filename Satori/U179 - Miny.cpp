#include <iostream>
#include <vector>
#include <cmath>


using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define ff first
#define ss second

vector<vector<int>> graph; 
vector<vector<int>> graph2; 
vector<pii> segment;
int base;

void build(int v, int l, int r){
    segment[v] = {l, r};
    if (v >= base) return;

    graph[v].push_back(v * 2);
    graph[v].push_back(v * 2 + 1);

    build(v * 2, l, (l + r) / 2);
    build(v * 2 + 1, (l + r) / 2 + 1, r);
}

void add_segment(int v, int l, int r) {
    l += base - 1;
    r += base + 1;
    v += base;

    while (l / 2 != r / 2) {
        if (l % 2 == 0) {
            graph[v].push_back(l + 1);
        }
        if (r % 2 == 1) {
            graph[v].push_back(r - 1);
        }
        l /= 2;
        r /= 2;
    }
}

vector<int> my_stack;
vector<bool> vis;
void dfs(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    for (int neigh : graph[v]) {
        dfs(neigh);
    }
    my_stack.push_back(v);
}

pii join_segments(pii a, pii b) {
    return {min(a.ff, b.ff), max(a.ss, b.ss)};
}


int act_comp;
vector<int> comp;
vector<pii> comp_segment;
void dfs2(int v) {
    if (vis[v]) return;
    comp[v] = act_comp;
    comp_segment[act_comp] = join_segments(comp_segment[act_comp], segment[v]);
    vis[v] = 1;
    for (int neigh : graph2[v]) {
        dfs2(neigh);
    }
}

void solve() {
    int n;
    cin >> n;
    //init
    base = 1 << int(ceil((double)log2(n)));
    graph.assign(base * 2, {});
    graph2.assign(base * 2, {});
    segment.assign(base * 2, {});
    comp_segment.assign(base * 2, {});
    comp.assign(base * 2, 0);

    vector<ll> pos(n), radius(n);

    for (int i = 0; i < n; i ++ ) {
        cin >> pos[i] >> radius[i];
    }


    //Graph Building
    build(1, 0, base - 1);
    for (int i = 0; i < n; i ++) {
        int pl = i, pr = i;

        int l = 0, r = i;
        while (l < r) {
            int mid = (l + r) / 2;
            if (pos[i] - radius[i] <= pos[mid]) r = mid;
            else l = mid + 1;
        }
        pl = l;

        l = i, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (pos[i] + radius[i] >= pos[mid]) l = mid;
            else r = mid - 1;
        }
        pr = l;

        add_segment(i, pl, pr);

    }
    for (int i = 0; i < base * 2; i ++ ) {
        for (int neigh : graph[i]) {
            graph2[neigh].push_back(i);
        }
    }

    vis.assign(2 * base, 0);
    for (int i = 1; i < base * 2; i++) {
        dfs(i);
    }
    vis.assign(2 * base, 0);
    act_comp = 0;

    while (my_stack.size()) {
        int v = my_stack.back();
        my_stack.pop_back();
        if (vis[v]) {
            continue;
        }

        comp_segment[act_comp] = segment[v];
        dfs2(v);
        act_comp++;

    }

    vector<vector<int>> graph3(act_comp);
    vector<int> indegree(act_comp, 0);
    for (int i = 0; i < base * 2; i ++) {
        for (int neigh : graph2[i]) {
            if (comp[neigh] == comp[i]) continue;
            graph3[comp[i]].push_back(comp[neigh]);
            indegree[comp[neigh]]++;
        }
    }

    
    for (int i = 0; i < act_comp; i++) {
        if (indegree[i] == 0) my_stack.push_back(i);
    }

    while (my_stack.size()) {
        int v = my_stack.back();
        my_stack.pop_back();

        for (int neigh : graph3[v]) {
            indegree[neigh]--;
            comp_segment[neigh] = join_segments(comp_segment[neigh], comp_segment[v]);
            if (indegree[neigh] == 0) {
                my_stack.push_back(neigh);
            }
        }

    }
    for (int i = 0; i < n; i ++ ) {
        cout << comp_segment[comp[i + base]].ss - comp_segment[comp[i + base]].ff + 1 << ' ';
    }

    cout << '\n';


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}
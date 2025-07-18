#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;
using ll = long long;

vector<int> tree;
vector<int> lazy;
int base = 0;

void pushLazy(int v){
    tree[v * 2 + 1] += lazy[v];
    tree[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v * 2] += lazy[v];
    lazy[v] = 0;
}


void editT(int l, int r, int val, int v, int vl, int vr){
    if (l <= vl && vr <= r){
        tree[v] += val;
        lazy[v] += val;
        return;
    }

    if (r < vl || vr < l) return;

    int mid = (vl + vr) / 2;
    pushLazy(v);
    editT(l, r, val, v * 2, vl, mid);
    editT(l, r, val, v * 2 + 1, mid + 1, vr);

    tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
}

int queryT(int l, int r, int v, int vl, int vr){
    if (l <= vl && vr <= r){
        return tree[v];
    }

    if (r < vl || vr < l) return 1e9;

    int mid = (vl + vr) / 2;
    pushLazy(v);
    return min(queryT(l, r, v * 2, vl, mid), queryT(l, r, v * 2 + 1, mid + 1, vr));

}


int query(int l, int r){
    return queryT(l, r, 1, 0, base - 1);
}



void edit(int l, int r, int val){
    editT(l, r, val, 1, 0, base - 1);
}


void solve(){
    int n, val;
    cin >> n;
    tree.clear();
    lazy.clear();
    
    base = 1 << (int)ceil(log2(n));
    tree.resize(2 * base, 0);
    lazy.resize(2 * base, 0);

    //cout << n << ' ' << base << '\n';
    unordered_map<int, int> mapka;
    unordered_map<int, int> mapka2;

    for (int i = 0; i < n; i++){
        cin >> val;

        int pop1 = -1;
        int pop2 = -1;

        if (mapka.find(val) != mapka.end()) pop1 = mapka[val];
        if (mapka2.find(val) != mapka.end()) pop2 = mapka2[val];

        if (pop1 != -1) edit(pop2 + 1, pop1, -1);
        edit(pop1 + 1, i, 1);

        if (query(0, i) == 0){
            cout << "boring\n";
            for (int j = i + 1; j < n; j++) cin >> val;
            return;
        }

        mapka2[val] = pop1;
        mapka[val] = i;
    }

    

    cout << "non-boring\n";
}

int main(){

    int q;
    cin >> q;

    while (q--){
        solve();
    }


    return 0;
}
#include <iostream>
#include <map>
#include <vector>


using namespace std;
using ll = long long;

const int base = 1 << 18;
const ll MOD = 1e9 + 7;

ll tree[base * 2];

void edit(int idx, ll val) {
    idx += base;

    tree[idx] = (tree[idx] + val) % MOD;

    idx /= 2;

    while (idx) {
        tree[idx] = (tree[idx * 2] + tree[idx * 2 + 1]) % MOD;
        idx /= 2;
    }
}

ll odp(int a, int b) {
    a += base - 1;
    b += base + 1;  

    ll w = 0;

    while (a / 2 != b / 2) {
        if (a % 2 == 0) w = (w + tree[a + 1]) % MOD;
        if (b % 2 == 1) w = (w + tree[b - 1]) % MOD;
        a /= 2;
        b /= 2;
    }

    return w;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, val;
    cin >> n;

    map<int, int> mapka;
    vector<int> tab;

    for (int i = 0; i < n; i++) {
        cin >> val;
        mapka[val] = 0;
        tab.push_back(val);
    }


    int akt = 1;

    for (auto & [k, v] : mapka) {
        v = akt++;
    }

    edit(0, 1);

    for (int i = 0; i < n; i++) {
        edit(mapka[tab[i]], odp(0, mapka[tab[i]] - 1));
    }

    cout << odp(1, akt - 1) << '\n';

    return 0;
}
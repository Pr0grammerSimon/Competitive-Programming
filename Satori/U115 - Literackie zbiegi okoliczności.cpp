#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;
using namespace std;

ll n;


int base = 1 << 17;
ll tree[1 << 18];

ll query(int l, int r){
    l += base - 1;
    r += base + 1;


    ll wynik = 0;
    while (l / 2 != r / 2){
        if (l % 2 == 0) wynik += tree[l + 1];
        if (r % 2 == 1) wynik += tree[r - 1];
        l /= 2;
        r /= 2;
    }

    return wynik;

}

void add(int idx){
    idx += base;
    tree[idx] = 1;
    idx /= 2;
    while (idx > 0){
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
        idx /= 2; 
    }
}

ll solve2(vector<ll> tab1, vector<ll> tab2){
    vector<int> wystapienie1(n + 1);
    vector<pair<int, int>> pary;
    for (int i = 0; i < n; i++) wystapienie1[tab1[i]] = i;
    for (int i = 0; i < n; i++) pary.push_back({wystapienie1[tab2[i]], i});

    sort(pary.begin(), pary.end());

    base = (1 << (int)ceil(log2(n)));
    
    for (int i = 0; i < 2 * base; i++) tree[i] = 0;

    ll wynik = 0;

    for (int i = 0; i < n; i++){
        wynik += query(0, pary[i].second);
        add(pary[i].second);
    }

    return wynik;
}

void solve(){
    cin >> n;
        
    vector<ll> ciag1(n);
    vector<ll> ciag2(n);
    vector<ll> ciag3(n);

    for (int i = 0; i < n; i++) cin >> ciag1[i];
    for (int i = 0; i < n; i++) cin >> ciag2[i];
    for (int i = 0; i < n; i++) cin >> ciag3[i];

    ll z = solve2(ciag1, ciag2) + solve2(ciag2, ciag3) + solve2(ciag3, ciag1);

    cout << (ll)(z - n * (n - 1) / 2) / 2 << '\n';

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;

    while (t--){
        solve();
    }

    return 0;
}
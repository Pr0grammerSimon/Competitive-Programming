#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll n, m;
const int MAXM = 2 * 1e5 + 7;
ll tabM[MAXM];

ll solve(vector<ll> tab, int pos) {
    if (tab.size() == 0) return 0;
    if (pos == m) {
        ll suma = 0;
        for (ll val : tab) suma += val;
        return suma;
    }

    vector<ll> tab1;
    vector<ll> tab2;
    for (ll val : tab) {
        if (val % tabM[pos]) tab1.push_back(val);
        else tab2.push_back(val);
    }

    if (pos % 2 == 0) return min(solve(tab1, pos + 1), solve(tab2, pos + 1));
    else return max(solve(tab1, pos + 1), solve(tab2, pos + 1));
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;
    vector<ll> tab(n);

    for (int i = 0; i < n; i++) cin >> tab[i];
    for (int i = 0; i < m; i++) cin >> tabM[i];

    if (m > 30) cout << 0 << '\n';
    else cout << solve(tab, 0);

    return 0;
}
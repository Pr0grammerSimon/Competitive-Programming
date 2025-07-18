#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int MAXN = 20;
const int MAXK = 1 << MAXN;
 
int tab[MAXN][MAXN];
int suma[MAXN];
int dp[MAXK][MAXN];
int suma2[MAXK][MAXN];
int krolestwa[MAXN];
 
void solve() {
    int n;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        suma[i] = 0;
        for (int j = 0; j < n; j++) {
            cin >> tab[i][j];
            suma[i] += tab[i][j];
        }
    }
 
    int K = 1 << n;
 
    for (int msk = 0; msk < K; msk++) {
        for (int i = 0; i < n; i++) {
            dp[msk][i] = 0;
        }
    }
 
    for (int msk = 1; msk < K; msk++) {
 
        int rozmiar = 0;
        for (int i = 0; i < n; i++) {
            if (msk & (1 << i)) {
                krolestwa[rozmiar++] = i;
            }
        }
 
        for (int i = 0; i < n; i++) {
            suma2[msk][i] = suma2[msk ^ (1 << krolestwa[0])][i] + tab[i][krolestwa[0]];
        }
 
        if (rozmiar == 1) {
            dp[msk][krolestwa[0]] = 1;
            continue;
        }
 
        for (int x = 0; x < rozmiar; x++) {
            int k = krolestwa[x];
            for (int y = 0; y < rozmiar; y++) {
                int k2 = krolestwa[y];
                if (k == k2) continue;
                if (dp[msk ^ (1 << k2)][k] && suma[k2] - suma2[msk ^ (1 << k)][k2] > 0) {
                    dp[msk][k] = 1;
                    break;
                }
            }
        }
    }
 
    int ile = 0;
    for (int i = 0; i < n; i++) {
        if (dp[K - 1][i]) {
            cout << i + 1 << ' ';
            ile++;
        }
    }
    if (!ile) cout << 0 << ' ';
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int q;
    cin >> q;
    while (q--) solve();
 
    return 0;
}
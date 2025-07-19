#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

const int MAXN = 500 + 1;

int dp[MAXN][MAXN * MAXN + 10];
int stala = MAXN * MAXN / 2;


ll fast(ll a, ll p) {
    if (p == 0) return 1;

    if (p % 2 == 0) {
        ll w = fast(a, p / 2);
        return (w * w) % MOD;
    }
    else return (fast(a, p - 1) * a) % MOD;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if ((n * (n + 1) / 2) % 2 == 1) {
        cout << 0 << '\n';
        return 0;
    }

    dp[0][stala] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j < MAXN * MAXN - i; j++) {
            dp[i][j] = (dp[i - 1][j - i] + dp[i - 1][j + i]) % MOD;
        }
    }

    cout << (dp[n][stala] * fast(2, MOD - 2)) % MOD << '\n';

    
    return 0;
}
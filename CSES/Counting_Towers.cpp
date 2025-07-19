#include <iostream>


using namespace std;
using ll = long long;

const int MAXN = 1e6 + 1;
const ll MOD = 1e9 + 7;

ll dp[MAXN][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i < MAXN; i++) {
        dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (4 * dp[i - 1][1] + dp[i - 1][0]) % MOD;
    }

    int q;
    cin >> q;


    while (q--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }


    return 0;
}
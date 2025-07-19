#include <iostream>
#include <vector>


using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, val;
    cin >> n >> m;

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 2, 0));

    for (int i = 1; i <= n; i ++ ) {
        cin >> val;
        if (val) {
            dp[i][val] = (dp[i - 1][val - 1] + dp[i - 1][val] + dp[i - 1][val + 1]) % MOD;
            if (i == 1) dp[i][val] = 1;
            continue;
        }

        if (i == 1) {
            for (int j = 1; j <= m; j++) dp[i][j] = 1;
            continue;
        }

        for (int j = 1; j <= m; j ++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
        }
    }

    ll result = 0;
    for (int j = 1; j <= m; j ++) {
        result = (result + dp[n][j]) % MOD;
    }

    cout << result;


    return 0;
}
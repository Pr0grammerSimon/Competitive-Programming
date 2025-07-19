#include <iostream>
#include <vector>


using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<ll>> dp(n + 2, vector<ll>(n + 2, 0));
    vector<int> tab(n + 1);

    for (int i = 1; i <= n; i++) cin >> tab[i];

    for (int i = n; i >= 1; i--) {
        ll sum1 = 0, sum2 = 0;
        for (int j = i; j <= n; j++) {
            if (j > i) sum1 += tab[j];

            if (i == j) dp[i][j] = tab[i];
            else dp[i][j] = max(tab[i] + sum1 - dp[i + 1][j], tab[j] + sum2 - dp[i][j - 1]);

            sum2 += tab[j];
        }
    }

    cout << dp[1][n] << '\n';

    return 0;
}
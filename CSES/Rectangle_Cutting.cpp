#include <iostream>
#include <vector>

using namespace std;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    for (int i = 0; i <= min(n, m); i++) dp[i][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= j - 1; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
            for (int k = 1; k <= i - 1; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}
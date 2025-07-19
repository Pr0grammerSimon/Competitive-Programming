#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<int> tab_a(n + 1);
    vector<int> tab_b(m + 1);

    for (int i = 1; i <= n; i++) cin >> tab_a[i];
    for (int i = 1; i <= m; i++) cin >> tab_b[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (tab_a[i] == tab_b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    vector<int> ans;

    int act_a = n;
    int act_b = m;

    while (act_a > 0 && act_b > 0) {
        if (tab_a[act_a] == tab_b[act_b]) {
            ans.push_back(tab_a[act_a]);
            act_a--;
            act_b--;
        }
        else if (dp[act_a - 1][act_b] > dp[act_a][act_b - 1]) {
            act_a--;
        }
        else act_b --;
    }

    reverse(ans.begin(), ans.end());


    cout << dp[n][m] << '\n';

    for (int val : ans) cout << val << ' ';


    return 0;
}
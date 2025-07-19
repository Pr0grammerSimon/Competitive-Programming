#include <iostream>
#include <vector>


using namespace std;

const int MAXN = 11;
const int MOD = 1e9 + 7;

vector<vector<pair<int, int>>> dp1[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    
    dp1[1].push_back({{1, 0}});
    dp1[1].push_back({{1, 1}});

    for (int i = 2; i <= n; i++) {
        for (auto tab : dp1[i - 1]) {
            dp1[i].push_back(tab);
            dp1[i][dp1[i].size() - 1].push_back({1, 0}); 
            dp1[i].push_back(tab);
            dp1[i][dp1[i].size() - 1].push_back({1, 1}); 
        }
        if (i == 2) {
            dp1[i].push_back({{2, 0}, {2, 0}});
        }
        for (auto tab : dp1[i - 2]) {
            dp1[i].push_back(tab);
            dp1[i][dp1[i].size() - 1].push_back({2, 0}); 
            dp1[i][dp1[i].size() - 1].push_back({2, 0}); 
        }
    }

    vector<vector<pair<int, int>>> possible = dp1[n];

    vector<vector<int>> dp(m, vector<int>(possible.size(), 0));
    
    vector<pair<int, int>> pary;
    
    for (int j = 0; j < possible.size(); j++) {
        bool good = 1;
        
        for (int i = 0; i < n; i++) {
            if (possible[j][i].first == 1 && possible[j][i].second == 0) {
                good = 0;
                break;
            }
        }
        if (good) dp[0][j] = 1;

        for (int j2 = 0; j2 < possible.size(); j2++) {
            good = 1;
            for (int i = 0; i < n; i++) {
                if (possible[j][i].first == 2) {
                    if (possible[j2][i].second == 1) {
                        good = 0;
                        break;
                    }
                }
                else{
                    if (possible[j][i].second == possible[j2][i].second) {
                        good = 0;
                        break;
                    }
                    
                }
            }
            if (good) {
                pary.push_back({j, j2});
            }

        }
    }

   for (int i = 1; i < m; i++) {
        for (auto & p : pary) {
            dp[i][p.first] = (dp[i][p.first] + dp[i - 1][p.second]) % MOD;
        }
   }

   int ans = 0;

   for (int j = 0; j < possible.size(); j++) {
        bool good = 1;
        for (int i = 0; i < n; i++) {
            if (possible[j][i].second == 1) {
                good = 0;
                break;
            }
        }

        if (good) ans = (ans + dp[m - 1][j]) % MOD;
   }

    cout << ans << '\n';


    return 0;
}
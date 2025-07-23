#include <iostream>
#include <string>
#include <vector>
#include <cmath>
 
using namespace std;
using ll = long long;
 
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll P1 = 2137;
const ll P2 = 1999;
 
const int MAXN = 3e3 + 7;
ll powers1[MAXN];
ll powers2[MAXN];
 
string new_string(pair<string, int>& a) {
    if (a.first.size() * a.second > a.first.size() + 2 + ceil(log10(a.second + 1))) return to_string(a.second) + "(" + a.first + ")";
    string s2 = "";
    for (int i = 0; i < a.second; i++) s2 += a.first;
    return s2;
}
 
pair<int, int> hashing(string & s) {
    int w1 = 0;
    int w2 = 0;
    for (int i = 0; i < s.size(); i++) {
        w1 = (w1 + powers1[i + 1] * s[i]) % MOD1;
        w2 = (w2 + powers2[i + 1] * s[i]) % MOD2;
    }
    return {w1, w2};
}
 
 
void solve(){
    string s;
    cin >> s;
 
    int n = s.size();
 
    vector<vector<pair<string, int>>> dp(vector<vector<pair<string ,int>>>(n, vector<pair<string, int>>(n, {"", 0})));
    vector<vector<pair<int, int>>> hashe(vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n)));
    vector<vector<int>> sizedp(vector<vector<int>>(n, vector<int>(n)));
    vector<vector<int>> sizedpall(vector<vector<int>>(n, vector<int>(n)));
 
    for (int i = n - 1; i >= 0; i--){
        for (int j = i; j < n; j++) {
            if (i == j) {
                dp[i][j] = {string(1, s[i]), 1};
                hashe[i][j] = hashing(dp[i][j].first);
                sizedp[i][j] = 1;
                sizedpall[i][j] = 1;
                //cout << i << ' ' << j << ' ' << dp[i][j].first << ' ' << dp[i][j].second << '\n';
                continue;
            }
 
 
 
 
            dp[i][j] = {new_string(dp[i][j - 1]) + string(1, s[j]), 1};
 
            int best_size = dp[i][j].first.size();
            int best_idx = j - 1;
 
            int test = 0;
            for (int k = i; k < j; k++){
 
                if (hashe[i][k] == hashe[k + 1][j]) {
                    int new_size = min(sizedp[i][k] + 2 + (int)ceil(log10(dp[i][k].second + dp[k + 1][j].second + 1)), sizedp[i][k] * (dp[i][k].second + dp[k + 1][j].second));
 
                    if (new_size <= best_size) {
                        best_size = new_size;
                        best_idx = k;
                    }
 
                }
                else{
                    int new_size = sizedpall[i][k] +  sizedpall[k + 1][j];
 
                    if (new_size < best_size) {
                        best_size = new_size;
                        best_idx = k;
                    }
                }
 
            }
 
            int k = best_idx;
            int act_len = dp[i][j].first.size();
 
 
            if (dp[i][k].first == dp[k + 1][j].first) {
                int new_size = min(sizedp[i][k] + 2 + (int)ceil(log10(dp[i][k].second + dp[k + 1][j].second + 1)), sizedp[i][k] * (dp[i][k].second + dp[k + 1][j].second));
 
                if (new_size <= act_len) {
                    dp[i][j] = {dp[i][k].first, dp[i][k].second + dp[k + 1][j].second};;
                }
 
            }
            else{
                int new_size = sizedpall[i][k] + sizedpall[k + 1][j];
 
                if (new_size < act_len) {
                    dp[i][j] = {new_string(dp[i][k]) + new_string(dp[k + 1][j]), 1};
                }
            }
 
            sizedp[i][j] = dp[i][j].first.size();
            hashe[i][j] = hashing(dp[i][j].first);
            sizedpall[i][j] = min(sizedp[i][j] + 2 + (int)ceil(log10(dp[i][j].second + 1)), sizedp[i][j] * dp[i][j].second);
            //cout << i << ' ' << j << ' ' << dp[i][j].first << ' ' << hashe[i][j] << '\n';
 
 
        }
 
    }
 
 
    cout << new_string(dp[0][n - 1]) << '\n';
 
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    powers1[0] = 1;
    powers2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        powers1[i] = (powers1[i - 1] * P1) % MOD1;
        powers2[i] = (powers2[i - 1] * P2) % MOD2;
    }
 
 
    int q;
    cin >> q;
 
    while (q--) solve();
 
    return 0;
}
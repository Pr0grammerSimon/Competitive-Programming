#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;
using ll = long long;
using pii = pair<int, int>;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, c;
    cin >> n;

    vector<pair<pii, int>> segments;

    map<int, int> scaling;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        segments.push_back({{a, b}, c});
        scaling[a] = 0;
        scaling[b] = 0;

    }

    int act = 1;

    for (auto & [k, v] : scaling) {
        v = act++;
    }

    vector<ll> dp(2 * n + 1, 0);
    vector<vector<pii>> end_segments(2 * n + 1, vector<pii>());

    for (int i = 0; i < n; i++) {
        end_segments[scaling[segments[i].first.second]].push_back({scaling[segments[i].first.first], segments[i].second});
    }

    for (int i = 1; i < 2 * n + 1; i++) {
        dp[i] = dp[i - 1];
        for (auto & p : end_segments[i]) {
            dp[i] = max(dp[i], dp[p.first - 1] + p.second);
        }
    }

    cout << dp[2 * n] << '\n';

}
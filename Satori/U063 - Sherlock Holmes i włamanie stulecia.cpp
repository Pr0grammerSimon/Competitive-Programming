#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

void solve(){
    int n, m;

    cin >> n >> m;
    
    vi tab(n + 1, 0);
    vi sumy(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> tab[i];
        sumy[i] = sumy[i - 1] + tab[i];
    }

    // {idx, val} (monotonic queue)
    // we want to fast calculate dp[i] = best score if someone start taking gold on suffix i
    deque<pii> q;
    q.push_back({n + 1, 0});
    for (int i = n; i >= 1; i--) {
        
        while (sumy[q.front().first - 1] - sumy[i - 1] > m) q.pop_front();
        int result = sumy[n] - sumy[i - 1] - q.front().second;
        while (q.size() && result <= q.back().second) q.pop_back();
        q.push_back({i, result});
    }
    
    cout << q.back().second << '\n';

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    while (q--) solve();


    return 0;
}
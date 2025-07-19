#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> pages(n);
    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
        for (int j = x - price[i]; j >= 0; j--) {
            dp[j + price[i]] = max(dp[j + price[i]], dp[j] + pages[i]);
        }
    }

    cout << dp[x] << '\n';


    return 0;
}
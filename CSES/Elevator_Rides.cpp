#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>



using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;


    cin >> n >> x;
    vi weight(n);

    for (int i = 0; i < n; i++) cin >> weight[i];

    const int K = 1 << n;

    vector<pair<int, int>> dp(K, {1e9, 0}); //minimum amount, minimum weight in last ride of eleveator
    dp[0] = {1, 0};

    for (int msk = 1; msk < K; msk ++) {
        for (int i = 0; i < n; i++) {
            if (msk & (1 << i)) {
                int new_amount = dp[msk ^ (1 << i)].first;
                int new_weight = dp[msk ^ (1 << i)].second;

                if (new_weight + weight[i] > x) {
                    new_weight = weight[i];
                    new_amount ++;
                }
                else new_weight += weight[i];

                if (dp[msk].first > new_amount) dp[msk] = {new_amount, new_weight};
                else if (dp[msk].first == new_amount && dp[msk].second > new_weight) dp[msk] = {new_amount, new_weight};
            }
        }
    }

    cout << dp[K - 1].first << '\n';
    

}
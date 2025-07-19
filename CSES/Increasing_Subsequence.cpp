#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>


using namespace std;
using ll = long long;
using vi = vector<int>;
using vpii = vector<pair<int, int>>;

const int MAXN = 2 * 1e5 + 7;

int dp[MAXN]; //dp[i] - minimal value on the end of some LIS of length i

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, val;
    cin >> n;

    int act_right = 0;

    for (int i = 0; i < n; i++) {
        cin >> val;

        int left = 0, right = act_right;

        while (left < right){
            int mid = (left + right + 1) / 2;
            if (dp[mid] < val) left = mid;
            else right = mid - 1;
        }

        dp[left + 1] = val;
        act_right = max(act_right, left + 1);
    }

    cout << act_right << '\n';

    return 0;
}
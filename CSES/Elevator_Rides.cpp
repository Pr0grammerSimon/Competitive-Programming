#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;

    vi weight(n);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> weight[i];

    vi dp(1 << n, 1e9);
    dp[0] = 0;
    

}

//in progress
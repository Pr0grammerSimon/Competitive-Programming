#include <bits/stdc++.h>

using namespace std;

int ost_pos[(int)1e6+7];
int fst_pos[(int)1e6+7];

int main(){
    int n;
    cin >> n;
    int bracia[n],dp[n+1];
    for (int i=0; i<n; i++){
        cin >> bracia[i];
        ost_pos[bracia[i]] = i+1;
    }
    for (int i=n-1; i>=0; i--){
        fst_pos[bracia[i]] = i+1;
    }
    dp[0] = 0;
    for (int i=1; i<=n; i++){
        dp[i] = dp[i-1];
        if (ost_pos[bracia[i-1]]==i) dp[i] = max(dp[i],dp[fst_pos[bracia[i-1]]-1]+1);
    }
    cout << dp[n];
}
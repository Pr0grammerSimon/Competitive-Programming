#include <iostream>


using namespace std;

const int MAXS = 1e5 + 7;
int dp[MAXS];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, val;
    cin >> n;

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        cin >> val;

        for (int i = MAXS - val; i >= 0; i--) {
            if (dp[i]) dp[i + val] = 1;
        }
    }

    int count = 0;

    for (int i = 1; i < MAXS; i++) if (dp[i]) count ++;
    cout << count << '\n';
    for (int i = 1; i < MAXS; i++) if (dp[i]) cout << i << ' ';
    

    return 0;
}
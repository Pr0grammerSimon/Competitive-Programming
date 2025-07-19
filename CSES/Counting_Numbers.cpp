#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int K = 19;


ll dp[K][11];

ll odp(ll a){
    if (a < 0) return 0;
    if (a == 0) return 1;

    vector<int> digits;
    while (a) {
        digits.push_back(a % 10);
        a /= 10;
    }

    reverse(digits.begin(), digits.end());

    ll act_result = 0;

    for (int i = 1; i < digits.size(); i++) {
        for (int j = 1; j < 11; j++){
            act_result += dp[i][j];
        }
    }

    bool git = 1;
    int popp = -1;
        cout << a << ' ' << act_result << ' ' << git << '\n';


    for (int i = 0; i < digits.size() - 1; i++) {
        

        for (int j = 1; j < digits[i]; j++) {
            
            for (int k = 0; k <= 10; k++) {
                if (k != j) act_result += dp[digits.size() - i - 1][k];
            }

        }

        cout << a << ' ' << act_result << ' ' << git << '\n';

        if (digits[i] == popp) {
            git = 0;
            break;
        }

        popp = digits[i];
    }

    cout << a << ' ' << act_result << ' ' << git << '\n';


    if (git) act_result += digits.back() + (digits.back() != popp);

    return act_result;

};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    for (int i = 0; i < 11; i++) dp[0][i] = 1;

    for (int i = 1; i < K; i++) {
        for (int j = 0; j <= 10; j++) {
            for (int j2 = 0; j <= 10; j++) {
                if (j == j2) continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][j2]);
            }
        }
    }

    ll a, b;

    //cin >> a >> b;

    for (int i = 11; i <= 220; i++) cout << odp(i) << '\n';

    //cout << odp(b) - odp(a - 1);



}

//problem in progress
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int K = 19;


ll dp[K][10];

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
        for (int j = 1; j < 10; j++){
            act_result += dp[i][j]; //numbers with less size
        }
    }

    if (digits.size() > 1) act_result ++; //0

    bool git = 1;
    int popp = -1;

    for (int j = 1; j < digits[0]; j++) {
        if (j == popp) continue;

        for (int k = 0; k < 10; k++) {
            if (k != j) act_result += dp[digits.size() - 0 - 1][k];
        }

    }

    if (digits.size() > 1) popp = digits[0];

    for (int i = 1; i < digits.size() - 1; i++) {

        for (int j = 0; j < digits[i]; j++) {
            if (j == popp) continue;

            for (int k = 0; k < 10; k++) {
                if (k != j) act_result += dp[digits.size() - i - 1][k];
            }

        }

        if (digits[i] == popp) {
            git = 0;
            break;
        }

        popp = digits[i];
    }


    if (git){
        for (int i = 0; i <= digits.back(); i++) {
            if (i != popp) act_result ++;
        }
    }

    return act_result;

};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    for (int i = 0; i < 10; i++) dp[1][i] = 1;

    for (int i = 2; i < K; i++) {
        for (int j = 0; j < 10; j++) {
            for (int j2 = 0; j2 < 10; j2++) {
                if (j == j2) continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][j2]);
            }
        }
    }

    ll a, b;

    cin >> a >> b;
    
    cout << odp(b) - odp(a - 1);

}
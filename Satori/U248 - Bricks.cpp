#include <iostream>

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;

    ll endT = 0, endC = 0, endS = 0;

    char c;

    for (int i = 0; i < n; i ++ ) {
        cin >> c;
        if (c == 'T') {
            endT++;
        }
        else if (c == 'C') {
            endC += endT;
        }
        else if (c == 'S') {
            endS += endC;
        }
    }   

    cout << endS << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}
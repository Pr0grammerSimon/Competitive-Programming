//Code for 13 points XD
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, a, b, c, o;


void solveBrut(){
    vector<int> perm1, perm2, perm3;

}

void solveCequalN(){
    if (a != b) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = n; i > a; i--) {
        cout << i << ' ';
    }
    for (int i = 1; i <= a; i++) cout << i << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++) cout << i << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++) cout << i << ' ';
    cout << '\n';
}


void solve() {
    cin >> n >> a >> b >> c >> o;
    solveCequalN();


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}
#include <iostream>


using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j ++ ) cout << (i ^ j) << ' ';
        cout << '\n';
    }


    return 0;
}
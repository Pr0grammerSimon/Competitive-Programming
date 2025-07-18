#include <iostream>


using namespace std;

int get_x_y(int x, int y) {
    int xorr = x ^ y;

    int w = 0, act_p = 1;
    while (xorr) {
        w += (xorr % 2) * act_p;
        act_p *= 2;
        xorr /= 2;
    }

    return w;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j ++ ) cout << get_x_y(i, j) << ' ';
        cout << '\n';
    }


    return 0;
}
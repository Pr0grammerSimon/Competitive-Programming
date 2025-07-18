#include <iostream>


using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> x >> y;
    x --; y--;

    int xorr = x ^ y;

    int w = 0, act_p = 1;
    while (xorr) {
        w += (xorr % 2) * act_p;
        act_p *= 2;
        xorr /= 2;
    }

    cout << w << '\n';



    return 0;
}
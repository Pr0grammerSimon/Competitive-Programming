#include <iostream>


using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> x >> y;
    x --; y--;

    cout << (x ^ y) << '\n';



    return 0;
}
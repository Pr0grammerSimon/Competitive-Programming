#include <iostream>

using namespace std;
using ll = unsigned long long;

const ll MOD = 4294967296;

struct Matrix{
    ll tab[65][65];

    Matrix() {
        for (int i = 0; i < 65; i++) {
            for (int j = 0; j < 65; j++) {
                tab[i][j] = 0;
            }
        }
    };
    
    Matrix operator *(Matrix other) {
        Matrix result;
        for (int i = 0; i < 65; i++) {
            for (int j = 0; j < 65; j++) {
                for (int k = 0; k < 65; k++) {
                    result.tab[i][j] = (result.tab[i][j] + tab[i][k] * other.tab[k][j]) % MOD;
                }
            }
        }
        return result;
    }
};

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    ll k;
    cin >> k;
    k ++;

    Matrix init;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            for (int k = 0; k < 8; k++) {
                int new_x = x + dx[k];
                int new_y = y + dy[k];
                if (new_x < 0 || new_y < 0 || new_x >= 8 || new_y >= 8) continue;
                init.tab[x * 8 + y][new_x * 8 + new_y] = 1;
            }
            //init.tab[x * 8 + y][x * 8 + y] = 1;
        }
    }
    for (int i = 0; i < 65; i++) init.tab[i][64] = 1;

    Matrix ans;
    ans.tab[0][0] = 1;


    while (k) {
        if (k % 2) {
            ans = ans * init;
        }

        init = init * init;
        k /= 2;
    }

    cout << ans.tab[0][64] << '\n';


    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200 + 7;

vector<int> sasiedzi[MAXN * MAXN]; //prawa strona do lewego
int matching[MAXN * MAXN]; //matching lewego do prawego

bool zablokowane[MAXN][MAXN];

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int odw[MAXN * MAXN];
int aktodw = 1;

bool match(int v) {
    //cout << aktodw << ' ' << v << '\n';
    if (odw[v] == aktodw) return 0;
    odw[v] = aktodw;

    for (int s : sasiedzi[v]) {
        if (matching[s] == 0) {
            matching[s] = v;
            return 1;
        }
    }

    for (int s : sasiedzi[v]) {
        if (match(matching[s])) {
            matching[s] = v;
            return 1;
        }
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    int x, y;

    for (int i = 0 ; i < m; i++) {
        cin >> x >> y;
        zablokowane[x][y] = 1;
    }

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            if (zablokowane[x][y]) continue;
            if ((x + y) % 2 != 0) continue;
            for (int i = 0; i < 8; i++) {
                int newy = y + dy[i];
                int newx = x + dx[i];
                if (newx <= 0 || newy <= 0 || newx > n || newy > n) continue;
                if (zablokowane[newx][newy]) continue;
                sasiedzi[(x - 1) * n + y].push_back((newx - 1) * n + newy);
            }
        }
    }

    int w = 0;

     for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            if (zablokowane[x][y]) continue;
            int v = (x - 1) * n + y;
            /*for (int s : sasiedzi[v]) {
                cout << v << "-> " << s << '\n';
            }*/
            if ((x + y) % 2 != 0) continue;
            aktodw = v;
            w += match(v);
        }
    }

    cout << n * n - w - m << '\n';






    return 0;
}
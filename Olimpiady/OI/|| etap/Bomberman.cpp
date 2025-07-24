#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

const int MAXN = 1e3 + 6;

char tab[MAXN][MAXN];
//najkrotsza droga, jezeli nic nie wybucha, jezeli wybucham ja, jezeli wybucha moja kolumna, jezeli wybucha moj wiersz, jezeli juz cos wybuchlo


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;

int nowy_typF(int aktx, int akty, int akt_typ, int newx, int newy) {
    int typ = 4;

    if (akt_typ == 0) {
        if (tab[newx][newy] == '#') {
            typ = 1;
        }
        else typ = 0;
    }
    else if (akt_typ == 1) {
        if (akty == newy) {
            typ = 2;
        }
        else{
            typ = 3;
        }
    }
    else if (akt_typ == 2 && akty == newy) typ = 2;
    else if (akt_typ == 3 && aktx == newx) typ = 3;

    return typ;
}


void bfs(pii idxx, vector<vector<vector<int>>> & dp) {
    queue<pair<pii, int>> kolejka;
    vector<vector<vector<int>>> odw(n, vector<vector<int>>(n, vector<int>(5, 0)));

    kolejka.push({idxx, 0});
    dp[idxx.first][idxx.second][0] = 0;
    odw[idxx.first][idxx.second][0] = 1;

    while (!kolejka.empty()) {
        int x = kolejka.front().first.first, y = kolejka.front().first.second;
        int typ = kolejka.front().second;
        kolejka.pop();

        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (newx < 0 || newy < 0 || newx >= n || newy >= n) continue; 
            if (tab[newx][newy] == 'X') continue;
                
            int nowy_typ = nowy_typF(x, y, typ, newx, newy);

            //cout << x << ' ' << y << ' ' << typ << " -> " << newx << ' ' << newy << ' ' << nowy_typ << '\n';
            if (!odw[newx][newy][nowy_typ] && !(tab[newx][newy] == '#' && nowy_typ == 4)) {
                kolejka.push({{newx, newy}, nowy_typ});
                dp[newx][newy][nowy_typ] = dp[x][y][typ] + 1;
                odw[newx][newy][nowy_typ] = 1;
            }
        }
    }
}

int wx, wy;

void usun(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return;
    if (tab[x][y] == 'X' || tab[x][y] == 'U') return;
    tab[x][y] = 'U';


    if (wx == x) usun(x, y - 1);
    if (wx == x) usun(x, y + 1);
    if (wy == y) usun(x - 1, y);
    if (wy == y) usun(x + 1, y);
}


int skadP[MAXN][MAXN];
void bfsOdp(pii p) {
    queue<pii> kolejka;
    kolejka.push(p);

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) skadP[i][j] = -2;
    }
    skadP[p.first][p.second] = -1;

    while (!kolejka.empty()) {
        int x = kolejka.front().first;
        int y = kolejka.front().second;
        kolejka.pop();

        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (newx < 0 || newy < 0 || newx >= n || newy >= n) continue; 
            if (tab[newx][newy] == 'X' || tab[newx][newy] == '#') continue;

            if (skadP[newx][newy] != -2) continue;
            skadP[newx][newy] = i;
            kolejka.push({newx, newy});
        }

        
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    pii poczatek_idx;
    pii koniec_idx;

    vector<vector<vector<int>>> dpp(n, vector<vector<int>>(n, vector<int>(5, 1e9)));
    vector<vector<vector<int>>> dpk(n, vector<vector<int>>(n, vector<int>(5, 1e9)));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tab[i][j];
            if (tab[i][j] == 'P') {
                poczatek_idx = {i, j};
            }
            else if (tab[i][j] == 'K') {
                koniec_idx = {i, j};
            }
        }
    }


    bfs(poczatek_idx, dpp);
    bfs(koniec_idx, dpk);

    int w = 1e9;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int minip = 1e9, minik = 1e9;
            for (int k = 0; k < 4; k++) {
                minip = min(minip, dpp[i][j][k]);
                minik = min(minik, dpk[i][j][k]);
            }
            if (w > minip + minik) {
                wx = i;
                wy = j;
                w = minip + minik;
            }
        }
    }
    if (w == 1e9) {
        cout << "NIE\n";
        return 0;
    }

    cout << w << '\n';

    usun(wx, wy);
    cout << wx + 1 << ' ' << wy + 1 << '\n';

    bfsOdp(poczatek_idx);

    string odp;


    int aktx = koniec_idx.first, akty = koniec_idx.second;
    while (aktx != poczatek_idx.first || akty != poczatek_idx.second) {
        int typ = skadP[aktx][akty];
        if (typ == 0) odp += "G";
        else if (typ == 1) odp += "D";
        else if (typ == 2) odp += "L";
        else odp += "P";
        
        aktx += -1 * dx[typ]; 
        akty += -1 * dy[typ]; 
    }

    reverse(odp.begin(), odp.end());
    cout << odp << '\n';
    

    return 0;
}
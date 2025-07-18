#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 3000;

char tab[MAXN][MAXN];
int nr[MAXN][MAXN];
int choice[MAXN][MAXN];

vector<pair<int, int>> indexes[MAXN * 2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;


    vector<pair<int, int>> values;

    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++) {
            nr[i][j] = 1e9;
            cin >> tab[i][j];
            indexes[i + j].push_back({i, j});
        }
    }

    nr[0][0] = 0;

    for (int i = 1; i < n * 2; i ++) {
        int min_choice = 0;

        for (auto & p : indexes[i]) {
            int nr_choice = 0;
            if (p.first == 0) {
                nr_choice = nr[p.first][p.second - 1];
            }
            else if (p.second == 0) {
                nr_choice = nr[p.first - 1][p.second];
            }
            else {
                nr_choice = min(nr[p.first - 1][p.second], nr[p.first][p.second - 1]);
            }
            choice[p.first][p.second] = nr_choice;
            min_choice = min(min_choice, nr_choice);
        }

        int min_char = 1000;

        for (auto & p : indexes[i]) {
            if (choice[p.first][p.second] == min_choice) min_char = min(min_char, int(tab[p.first][p.second]));
        }
        for (auto & p : indexes[i]) {
            if (choice[p.first][p.second] == min_choice && tab[p.first][p.second] == min_char) nr[p.first][p.second] = 0;
        }
    
    }

    int aktx = n - 1, akty = n - 1;
    string s;
    while (aktx >= 0 && akty >= 0) {
        s += tab[aktx][akty];
        if (aktx == 0) akty--;
        else if (akty == 0) aktx--;
        else {
            if (nr[aktx - 1][akty] < nr[aktx][akty - 1]) aktx--;
            else akty--;
        }
    }

    reverse(s.begin(), s.end());
    cout << s << '\n';
    
    return 0;
}
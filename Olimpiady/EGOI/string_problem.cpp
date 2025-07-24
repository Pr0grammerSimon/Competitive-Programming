#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using vi = vector<int>;


const int MAXN = 2e5 + 7;
bool odw[MAXN];

vector<pair<int, int>> struny;


void dfs(int v) {
    cout << v << ' ' << struny[]
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n;

    vector<int> grupy(2 * n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        grupy[(a + b) % (2 * n)] ++;
        struny.push_back({a, b});
    }

    int w = n;
    int w_grupa = 1;

    for (int i = 1; i < 2 * n; i += 2) {
        int aktw = n;
        aktw -= grupy[i];
        if (aktw < w) w_grupa = i;
        w = min(aktw, w);
    }


    vector<int> calkowita_zmiana;
    cout << w << '\n';

    for (int i = 0; i < n; i++) {
        if ((struny[i].first + struny[i].second) % (2 * n) == w_grupa) {
            odw[struny[i].first] = 1;
            odw[struny[i].second] = 1;
        } 
        else if (!odw[struny[i].first]) {
            dfs(struny[i].first);
        }
        else if (!odw[struny[i].second]) {
            dfs(struny[i].second);
        }
        else{
            cout << i << '\n';
            calkowita_zmiana.push_back(i);
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        if (!zajete_pola[i]) {
            cout << i << ' ' << struny[calkowita_zmiana[0]].first << ' ' << struny[calkowita_zmiana[0]].second << '\n';
        }
    }

    



    return 0;
}
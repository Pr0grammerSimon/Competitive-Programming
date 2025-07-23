#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using vi = vector<int>;


const int MAXN = 2e5 + 7;
vi graf[MAXN];
vi graf2[MAXN];
int odl1[MAXN];
bool odw[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n;

    vector<int> grupy(2 * n, 0);
    vector<pair<int, int>> struny;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        grupy[(a + b) % (2 * n)] ++;

        struny.push_back({a, b});
    }

    int w = n;
    int w_grupa = 1;

    for (int i = 1; i < 2 * n; i+=2) {
        int aktw = n;
        aktw -= grupy[i];
        if (aktw < w) w_grupa = i;
        w = min(aktw, w);
    }


    vector<bool> zajete_pola(2 * n, 0);
    cout << w << '\n';

    for (int i = 0; i < n; i++) {
        if ((struny[i].first + struny[i].second) % (2 * n) == w_grupa) {
            zajete_pola[struny[i].first] = 1;
            zajete_pola[struny[i].second] = 1;
        } 
        else if (!zajete_pola[(w_grupa - struny[i].first + 2 * n) % (2 * n)]) {
            a = struny[i].first;
            b = (w_grupa - struny[i].first + 2 * n) % (2 * n);
            cout << i << ' ' << struny[i].second << ' ' << b << '\n';
            zajete_pola[a] = 1;
            zajete_pola[b] = 1;
        }
        else if (!zajete_pola[(w_grupa - struny[i].second + 2 * n) % (2 * n)]) {
            a = struny[i].second;
            b = (w_grupa - struny[i].second + 2 * n) % (2 * n);
            cout << i << ' ' << struny[i].first << ' ' << b << '\n';
            zajete_pola[a] = 1;
            zajete_pola[b] = 1;
        }
    }

    



    return 0;
}
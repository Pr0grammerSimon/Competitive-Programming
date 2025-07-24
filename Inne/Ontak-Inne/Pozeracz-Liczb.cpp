#include <iostream>
#include <unordered_set>
#include <vector>


using namespace std;
using ll = __int128;


const ll MOD = 999999999999999989;
const ll P = 2137;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> tab(n);
    unordered_set<ll> hashe;
    vector<ll> powers(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        powers[i] = (powers[i - 1] * P) % MOD;
    }

    for (int i = 0; i < n; i++) {
        cin >> tab[i];
    }

    vector<int> ile(n + 1, 0);


    for (int i = 0; i < n; i++) {
        ll akt_hash = 0;
        for (int j = i; j < n; j++) {
            ile[tab[j]]++;
            if (ile[tab[j]] == 1) {
                akt_hash = (akt_hash + tab[j] * powers[tab[j]]) % MOD;
                hashe.insert(akt_hash);
            }

        }
        for (int j = i; j < n; j++) {
            ile[tab[j]]--;
        }
    }

    cout << hashe.size() << '\n';



    return 0;
}
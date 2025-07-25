#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;
using pii = pair<int, int>;

void solve(){
    int n, val;
    cin >> n;

    set<pair<int, pii>, greater<pair<int, pii>>> secik; //wynik, {ostatni, przed ostatni}
    map<int, vector<pair<int, pii>>> mapka1; //ostatni
    map<int, vector<pair<int, pii>>> mapka2; //przed ostatni

    secik.insert({0, {0, 0}});
    mapka1[0].push_back({0, {0, 0}});
    mapka2[0].push_back({0, {0, 0}});

    for (int _ = 0; _ < n; _++) {
        cin >> val;

        vector<pair<int, pii>> best_wyniki;

        auto wsk = secik.begin();

        while (wsk != secik.end()) {
            pair<int, pii> popval = *wsk;
            if (popval.second.first != val && popval.second.second != val && (best_wyniki.size() == 0 || best_wyniki.back().second.second != popval.second.first)) best_wyniki.push_back({popval.first + 1, {val, popval.second.first}});
            if (best_wyniki.size() == 2) break;
            wsk++;
        } 

        for (auto & nowe : best_wyniki) {
            vector<pair<int, pii>> nowa_1 = mapka1[nowe.second.first];
            nowa_1.push_back(nowe);
            vector<pair<int, pii>> wynik;
            

            sort(nowa_1.begin(), nowa_1.end());
            for (int i = nowa_1.size() - 1; i >= 0; i--) {
                if (i == nowa_1.size() - 1 || (nowa_1[i].second != nowa_1[i + 1].second)) {
                    wynik.push_back(nowa_1[i]);
                }
                else secik.erase(nowa_1[i]);
            }   
            while (wynik.size() >= 3) {
                secik.erase(wynik.back());
                wynik.pop_back();
            }
            for (auto val : wynik) secik.insert(val);

            mapka1[nowe.second.first] = wynik;
            



            vector<pair<int, pii>> nowa_2 = mapka2[nowe.second.second];
            nowa_2.push_back(nowe);
            wynik.clear();
            

            sort(nowa_2.begin(), nowa_2.end());
            for (int i = nowa_2.size() - 1; i >= 0; i--) {
                if (i == nowa_2.size() - 1 || (nowa_2[i].second != nowa_2[i + 1].second)) {
                    wynik.push_back(nowa_2[i]);
                }
                else secik.erase(nowa_2[i]);
            }   

            while (wynik.size() >= 3) {
                secik.erase(wynik.back());
                wynik.pop_back();
            }
            for (auto val : wynik) secik.insert(val);

            mapka2[nowe.second.second] = wynik;
            
            
            
        }

    }


    cout << (*secik.begin()).first << '\n';

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;


    while (q--) solve();



    return 0;
}
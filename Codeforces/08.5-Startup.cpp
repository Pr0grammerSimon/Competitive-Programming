#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int q, a, b;

    cin >> q;

    while (q--){
        int n, k;
        cin >> n >> k;

        map<int,int> mapka;

        for (int i=0; i<n; i++){
            cin >> a >> b;
            mapka[a] += b;
        }


        vector<int> tablica;
        for (auto [key, val] : mapka){
            tablica.push_back(val);
        }

        sort(tablica.begin(), tablica.end());

        int wynik = 0;

        for (int i=tablica.size()-1; i>=max(0,(int)tablica.size()-k); i--){
            wynik += tablica[i];
        }

        cout << wynik << endl;
    }


    return 0;
}
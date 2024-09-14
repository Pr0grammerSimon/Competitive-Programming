#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,a,k;
    cin >> n;
    
    vector<pair<long double,int>> lista(0);
    
    
    for (int i=0; i<n ; i++){
        cin >> a >> k;
        lista.push_back({a/k,a});
    }
    
    sort(lista.begin(),lista.end());
    
    int licznik=0;
    int akt_mini_wybieg=2e9;
    
    for (int i=n-1; i>=0; i--){
        if (akt_mini_wybieg >= lista[i].second){
            akt_mini_wybieg = lista[i].first;
            licznik++;
        }
    }
    
    cout << licznik << endl;
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> kolejka;
    

    
    for (int i=1; i<=n; i++){
        int a;
        cin >> a;
        kolejka.push({a,i});
    }
    
    int akt_idx=0;
    long long wynik=0;
    
    while (!kolejka.empty()){
        
        int val = kolejka.top().first;
        int idx = kolejka.top().second;
        
        kolejka.pop();
        
        if (idx>akt_idx){
            wynik += (long long)(idx-akt_idx)*val;
            akt_idx = idx;
        }
        
    }
    
    cout << wynik << '\n';
    
    return 0;
}
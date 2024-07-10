#include <bits/stdc++.h>

using namespace std;

pair<vector<int>,int> wagi[100001];

int main(){
    int n,m,a,b,val;
    cin >> n >> m;
    
    vector<vector<int>> graf(0,vector<int>());
    
    for (int i=0; i<m; i++){
        cin >> a >> b >> val;
        graf[b].push_back(a);
        wagi[a].first.push_back(val);
    }
    //cout << "dd";
    for (int i=0; i<n; i++){
        sort(wagi[i+1].first.begin(),wagi[i+1].first.end());
        wagi[i+1].second = wagi[i+1].first.size();
        for (int j=0; j<wagi[i+1].second; j++){
            cout << wagi[i+1].first[j] << endl;
        }
    }
        
    
    
    return 0;
    
}
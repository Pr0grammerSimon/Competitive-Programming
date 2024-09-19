#include <bits/stdc++.h>

using namespace std;


const int MAXN = 200001;

int wyniki[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n,t,d;
    
    cin >> n >> t >> d;
    
    int a,b;
    
    vector<pair<int,int>> ochroniarze; //kiedy i 0 : zaczyna, 1 : konczy
    
    for (int i=0; i<n; i++){
        cin >> a >> b;
        ochroniarze.push_back({a,0});
        ochroniarze.push_back({b+1,1});
    }
    
    sort(ochroniarze.begin(),ochroniarze.end());
    
    
    stack<int> stos_ochroniarzy;
    
    for (auto [idx, co] : ochroniarze){

        if (co==0){ //ochroniarz zaczyna przerwe
            stos_ochroniarzy.push(idx);
        }
        else{ //ochroniarz konczy przerwe
            int idx_2 = stos_ochroniarzy.top();
            int ile_na_wypoczynku = stos_ochroniarzy.size();
            stos_ochroniarzy.pop();
            
            wyniki[ile_na_wypoczynku] += max(0,idx-idx_2-t+1);
            
        }
    }
    
    wyniki[0] = d-t+1;
    
    for (int i=0; i<MAXN; i++){
        if (wyniki[i]==0) break;
        cout << i << " " << wyniki[i] << endl;
    }
    
    

    return 0;
}
#include <bits/stdc++.h>

int main()
{
    using namespace std;
    
    int n,typ,pozycja,time_,y,x;
    cin >> n;
    
    map<int,int> przekatne_1;
    map<int,int> przekatne_2;
    
    for (int i=0; i<n; i++){
        cin >> typ >> pozycja >> time_;
        if (typ == 1){
            x = pozycja;
            y = 0-time_;
        }
        else{
            x = 0-time_;
            y = pozycja;
        }
        
        if (typ == 1){
            if (przekatne_1.find(x+y) != przekatne_1.end()){
                przekatne_1[x+y] += 1;
            }
            else{
                przekatne_1[x+y] = 1;
            }
        }
        
        if (typ == 2){
            if (przekatne_2.find(x+y) != przekatne_2.end()){
                przekatne_2[x+y] += 1;
            }
            else{
                przekatne_2[x+y] = 1;
            }
        }
        
        
        
        
    }
    
    int wynik = 0;
    
    for (auto [k,v] : przekatne_1){
        if (przekatne_2.find(k) != przekatne_2.end()){
            wynik += min(v,przekatne_2[k]);
        }
    }
    
    cout << wynik;
    
    

    return 0;
}
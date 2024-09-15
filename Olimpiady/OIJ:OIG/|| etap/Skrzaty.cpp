#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    
    int ilosc_skrzatow,ilosc_godzin;
    cin >> ilosc_skrzatow >> ilosc_godzin;
    
    
    set<int> osiagalne;
    set<int> nieosiagalne;
    
    osiagalne.insert(1);
    
    for (int i=1; i<=ilosc_skrzatow; i++) nieosiagalne.insert(i);
    
    for (int h=0; h<ilosc_godzin; h++){
        int n;
        cin >> n;
        
        int ilosc_osiagalnych = osiagalne.size();
        
        int skrzat;
        set<int> skrzaty;
        
        for (int i=0; i<n; i++){
            cin >> skrzat;
            skrzaty.insert(skrzat);
            
            if (osiagalne.find(skrzat)!=osiagalne.end()) ilosc_osiagalnych--;
        }
        if (ilosc_osiagalnych>0){
            for (int skrzat : nieosiagalne){
                if (skrzaty.find(skrzat)==skrzaty.end()){
                    osiagalne.insert(skrzat);
                }
            }
            nieosiagalne = {};
            for (int skrzat : skrzaty){
                if (osiagalne.find(skrzat)==osiagalne.end()){
                    nieosiagalne.insert(skrzat);
                }
            }
        }
        
        if (osiagalne.find(ilosc_skrzatow)!=osiagalne.end()){
            cout << h << endl;
            return 0;
        }
        
        
    }
    
    
    cout << ilosc_godzin << endl;
    return 0;
}
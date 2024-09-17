//I'm doing a graph (path) where node[i] is the farthest stone possible to reach from stone i
//When I have graph, I'm doing a jump pointers

#include <bits/stdc++.h>
using namespace std;




int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int ilosc_kamyczkow,skok;
   
    cin >> ilosc_kamyczkow >> skok;
    int skoki[ilosc_kamyczkow-1];
    
    for (int i=0; i<(ilosc_kamyczkow-1); i++){
        cin >> skoki[i];
    }
    
    const int LOG=20;
    int jump[ilosc_kamyczkow][LOG];
    
    int right = 0,akt_skok=0;
    
    for (int left=0; left<ilosc_kamyczkow; left++){
        while (right < ilosc_kamyczkow-1 && (skoki[right]+akt_skok) <= skok){
            akt_skok += skoki[right];
            right++;
        }
        jump[left][0] = right;
        akt_skok -= skoki[left];
    }
    
    for (int i=1; i<LOG; i++){
        for (int kamyczek=0; kamyczek<ilosc_kamyczkow; kamyczek++){
            jump[kamyczek][i] = jump[jump[kamyczek][i-1]][i-1];
        }
    }
    
    int q,a,b;
    cin >> q;
    
    for (int i=0; i<q; i++){
        cin >> a >> b;
        a--;b--;
        if (a>b) swap(a,b);
        if (a==b) cout << 0 << endl;
        else{
            int wynik=0;
            for (int o_ile_skok=LOG-1; o_ile_skok>=0; o_ile_skok--){
                if (jump[a][o_ile_skok] < b){
                    a=jump[a][o_ile_skok];
                    wynik += (1<<o_ile_skok);
                }
            }
            cout << wynik+1 << endl;
        }
        
    }
    
    
    
    
    
    return 0;
}
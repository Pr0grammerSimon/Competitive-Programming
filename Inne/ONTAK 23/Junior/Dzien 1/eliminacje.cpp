#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+7; 

int tablica[MAXN][5];
int druzyny_akt[MAXN];

int check(int a,int b){
    int ile_a=0,ile_b=0;
    if (a==b or a==-1) return -1;
    for (int i=0; i<5;i++){
        if (tablica[a][i] > tablica[b][i]) ile_a++;
        else ile_b++;
    }
    
    if (ile_a>2) return a;
    if (ile_b>2) return b;
    return -1;
    
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,q;
    cin >> n >> q;
    
    for (int i=0; i<5; i++){
        for (int j=0; j<n; j++){
            cin >> tablica[j][i];
        }
    }
    
    int kandydat=0,w;
    

    
    
    
    int zapytanie,druzyna,jest_2,jest;

    
    for (int k=0; k<q; k++){
        cin >> zapytanie;

        kandydat = -1;
        for (int i=0; i<zapytanie; i++){
            cin >> druzyna;
            druzyny_akt[i] = druzyna;
            w = (check(kandydat,druzyna-1));
            if (w==kandydat) kandydat=druzyna-1;
            
        }
        jest = true;
        for (int i=0; i<zapytanie; i++){
            if (check(druzyny_akt[i]-1,kandydat) == kandydat){
                jest = false;
                break;
            }
            
        }
        
        
        if (jest){
            cout << "TAK "<< kandydat+1 << '\n';
        }
        
        else{
            cout << "NIE\n";
        }
    }
    
    return 0;
}
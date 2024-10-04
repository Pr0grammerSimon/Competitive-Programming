#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int klocki[MAXN];
long long sumy[MAXN];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin >> n >> m;
    
    long long suma=0;
    
    for (int i=0; i<n; i++){
        cin >> klocki[i];
        suma+=klocki[i];
        sumy[i] = suma;
    }
    
    for (int i=0; i<m; i++){
        cin >> k;
        
        
        vector<long long> pref(n,0); //Ile dodatkowo dojdzie nam klockow z lewej strony
        vector<long long> suf(n,0); //Ile dodatkowo dojdzie nam klockow z prawej strony
        
        long long akt_suma=0;
        for (int i=0; i<n; i++){
            pref[i] = akt_suma;
            akt_suma = max((long long)0, akt_suma-(k-klocki[i]));
        }
        akt_suma=0;
        for (int i=n-1; i>=0; i--){
            suf[i] = akt_suma;
            akt_suma = max((long long)0, akt_suma-(k-klocki[i]));
        }
        
        int wynik=0,prawo = -1;
        for (int lewo=0; lewo<n; lewo++){
        
            while (prawo+1 < n && ((lewo-1 >= 0 && ((long long)sumy[prawo+1]-sumy[lewo-1] + pref[lewo] + suf[prawo+1]) >= (long long)(prawo+1-lewo+1)*k ) || ((lewo-1)<0 && ((long long)sumy[prawo+1] + pref[lewo] + suf[prawo+1]) >= (long long)(prawo+1-lewo+1)*k ) )){
                prawo++;
            }
            
            wynik = max(wynik, prawo-lewo+1);
        }
        
        cout << wynik << " ";
    }
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long q,n,k,suma;
    cin >> q;
    for (int j=0; j<q; j++){
        cin >> n >> k;
        int tablica[n];
        for (int i=0; i<n; i++){
            cin >> tablica[i];
        }
        while (true){
            suma = 0;
            for (int i=0; i<n; i++){
                suma += tablica[i];
                tablica[i] /= 2;
            }
            
            k/=2;
            if (suma%2==1){
                cout << "Alicja"<<endl;
                break;
                
            }
            if (k<=0 || suma<=0){
                cout << "Bob"<<endl;
                break;
            }

            
        }
    }
    
    
}
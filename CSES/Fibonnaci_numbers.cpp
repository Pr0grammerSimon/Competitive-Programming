#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9+7;

long long macierze[63][2][2];


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    macierze[0][0][0] = 1;
    macierze[0][0][1] = 1;
    macierze[0][1][0] = 1;
    macierze[0][1][1] = 0;
    
    
    for (long long i=1; i<64; i++){
        for (long long y=0; y<2; y++){
            for (long long x=0; x<2; x++){
                
                long long suma = 0;
                
                for (long long j=0; j<2; j++){
                    suma += ((long long)macierze[i-1][y][j]*macierze[i-1][j][x]) % MOD;
                }
                
                
                macierze[i][y][x] = suma;
               // cout << y << " " << x << " " << suma << endl;
            }
        }
    }
    
    
        long long n;
        cin >> n;
        
        if (n>1){
            n-=1;
            long long akt_fib[2][2];
            for (long long i=62; i>=0; i--){
                if (n>=((long long)1<<i)) {
                    for (long long y=0; y<2; y++){
                        for (long long x=0; x<2; x++){
                            akt_fib[y][x]=macierze[i][y][x];
                        }
                    }
                    
                    n-=((long long)1<<i);
                    break;
                }
            }
            
            
            for (long long i=62; i>=0; i--){
                
                if (n>=((long long)1<<i)) {
                    
                    long long wyniki[2][2];
                    
                    for (long long y=0; y<2; y++){
                        for (long long x=0; x<2; x++){
                            
                            
                            long long suma = 0;
                            
                            for (long long j=0; j<2; j++){
                                suma += ((long long)macierze[i][j][x]*akt_fib[y][j]) % MOD;
                            }
                            
                            
                            wyniki[y][x] = suma % MOD;
                            
                        }
                    }
                    for (long long y=0; y<2; y++){
                        for (long long x=0; x<2; x++){
                            akt_fib[y][x] = wyniki[y][x];
                        }
                    }
                    
                    
                    
                    n-=((long long)1<<i);
                }
                
                
            }
            cout << akt_fib[0][0] << endl;
            
        }
        else if (n==0) cout << 0 << endl;
        else cout << 1 << endl;
    
    return 0;
}
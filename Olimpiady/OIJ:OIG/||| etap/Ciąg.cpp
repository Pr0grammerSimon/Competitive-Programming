//If you want to explain write to me on discord tapik_it
//In my solution I dividing sequence to the boxes
// [ [2 2 3 3] , [4 4 4 5 5 5] ] this is one of the boxes, because is box where in first subbox length is 2 * 2 and in second 2 * 3 (is multiply of 2)


#include <bits/stdc++.h>

using namespace std;

const int N = 1e8;
long long n;



long long B[1000000];

int main()
{
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    
    
    if (n==1) cout << 1;
    else{
        B[1] = 1;
        B[2] = 2;
        B[3] = 4;
        B[4] = 6;
        B[5] = 9;
        //B[i] - first position of number i in sequence


        

        long long point = 3;
        long long ile=1;

        long long akt_pozycja_boxa = 1;
        long long akt_suma_2 = 1;
        
        
        
        for (long long i=2; i<N; i++){

            if ( i > 4){ 
                B[i+1] = (B[i]+point);
                ile++;
                if (ile==(B[point+1]-B[point])){
                    ile=0;
                    point++;
                }
            }

            if ( (akt_pozycja_boxa + i * (  ( ( (B[i+1]-1) * B[i+1])/2 ) - ( ((B[i]-1) * B[i]) / 2)  ) ) >= n){
                for (long long j=B[i]; j<B[i+1]; j++){
                   
                    if ((akt_pozycja_boxa + (j*i) ) >= n){
                        long long liczba_w_boxie = n-akt_pozycja_boxa;
                        cout << akt_suma_2+((liczba_w_boxie-1)/j)+1;
                        return 0;
                    }
                    akt_suma_2 += i;
                    akt_pozycja_boxa += ((long long)j*i);
                }
                
            }
            akt_pozycja_boxa += ( i * (  ( ( (B[i+1]-1) * B[i+1])/2 ) - ( ((B[i]-1) * B[i]) / 2)  ) );
            akt_suma_2 += (i * (B[i+1]-B[i]));
            
            

        
        }
        
        
    }
    return 0;
}
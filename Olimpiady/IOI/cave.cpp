#include"cave.h"
#include <bits/stdc++.h>
using namespace std;
 
int tryCombination(int S[]);
 
void answer(int S[],int D[]);
 
void exploreCave(int N){
    int D[N],S[N],w=0,w_2=0;
    
    if(N==1) {  
        D[0] = 0; S[0] = 1;
        if(tryCombination(S)==0) S[0] = 0;
        answer(S, D);
    }
    
    
    for (int i=0; i<N; i++) D[i] = -1;
    bool good[N];
   
    for (int akt=0; akt<N; akt++){
        for (int i=0; i<N; i++) if(D[i] == -1) S[i] = 0;
        w = tryCombination(S);
        
        int l = 0,r=N-1,mid,key=1;
        while (l<r){
            if (!(w == -1 || w > akt)){
                for (int i=l; i<=r; i++){
                    if (D[i] == -1) S[i] = (S[i]+1)%2;
                }
            }   
            mid = (l+r)/2;
            for (int i=l; i<=mid; i++) if (D[i] == -1) S[i] = (S[i]+1)%2;
            w = tryCombination(S);
            if (w == akt){
                r = mid;
                key = (S[l]+1)%2;
            }
            else{
                l = mid+1;
                key = S[l];
            }
            
        }
        D[l] = akt;
        S[l] = key;

    }

        
    answer(S,D);

}
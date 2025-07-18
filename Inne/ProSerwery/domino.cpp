#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+7;

int h[MAXN];
int odl[MAXN];
int sum[MAXN];

int naj_domino[MAXN];

int dp[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    int n;

    cin >> n;
    
    odl[n] = 1e7;
    
    for (int i=0; i<n; i++){
        cin >> h[i];
    }
    
    for (int j=0; j<n-1; j++){
        cin >> odl[j];
        sum[j+1] = sum[j] + odl[j];
    }

    int naj_mozliwy=0,wynik=0;
    naj_domino[0] = -1;
    

    

    for (int i=0; i<n; i++){
        dp[i] = dp[naj_domino[i]]+i-naj_domino[i]-1;
        wynik = max(wynik,dp[i]);

        for (int j=naj_mozliwy+1; j<n; j++){
            if ((sum[j]-sum[i])<h[i]){
                naj_domino[j]=i;
                naj_mozliwy=j;
            }
            else{
                break;
            }
        }
    }
    
    cout << wynik;

    


}
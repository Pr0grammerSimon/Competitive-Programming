#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1001;
long long n,dodatkowa,maxi,mini,w;
long long grid[MAXN][MAXN];
long long dp[MAXN][MAXN];

long long check(long long v){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (grid[i][j]>v){
                dp[i][j]=1;
            }
            else if (grid[i][j]<v){
                dp[i][j]=-1;
            }
            else{
                dp[i][j]=1;
            }
            
            dodatkowa = 0;
            if (((i-1)>=0) || ((j-1)>=0)){
                dodatkowa = -1e9+3;
                if ((i-1)>=0) dodatkowa = max(dodatkowa,dp[i-1][j]);
                if ((j-1)>=0) dodatkowa = max(dodatkowa,dp[i][j-1]);
            }
            
            dp[i][j] += dodatkowa;
        }
    }
    maxi = dp[n-1][n-1];

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (grid[i][j]>v){
                dp[i][j]=1;
            }
            else if (grid[i][j]<v){
                dp[i][j]=-1;
            }
            else{
                dp[i][j]=-1;
            }
            
            dodatkowa = 0;
            
            if ((i-1)>=0 || (j-1)>=0){
                dodatkowa = 1e9+3;
                if ((i-1)>=0) dodatkowa = min(dodatkowa,dp[i-1][j]);
                if ((j-1)>=0) dodatkowa = min(dodatkowa,dp[i][j-1]);

            }
            
            dp[i][j] += dodatkowa;
        }
    }
    

    mini = dp[n-1][n-1];
    if (mini <= 0 && 0 <= maxi) return 1;
    if (mini>0) return 2;
    else return 3;
}


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    
    long long lewa = 1;
    long long prawa = 1e9+2;
    long long mid;
    
    
    
    while (lewa < prawa){
        mid = (lewa+prawa+1)/2;
        w = check(mid);
        if (w==1){
            lewa = mid;
        }
        else if (w==2){
            lewa = mid+1;
        }
        else{
            prawa = mid-1;
        }
    }
    cout << lewa;
    
    
    return 0;
    
}
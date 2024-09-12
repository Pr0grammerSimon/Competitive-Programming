#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e6;

int graf[MAXN+1];
int wyniki[MAXN+1][2];


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n,k;
    cin >> n;

    
    for (int i=2; i<n+1; i++){
        cin >> k;
        
        graf[i] = k;
    }



    for (int v=n; v>0; v--){
        
        
        if (wyniki[v][1]>0){
            wyniki[v][0]++;
            wyniki[v][1]--;
        }
        else{
            wyniki[v][1]++;
        }

        wyniki[graf[v]][0] += wyniki[v][0];
        wyniki[graf[v]][1] += wyniki[v][1];


    }

    cout << wyniki[1][0];
    
    return 0;
}
#include<bits/stdc++.h>

using namespace std;


int n, m;
int tab[1000][1000];
int layer[1000][1000];


int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int ile;

int liczba[4] = {1,5,4,3};

void solve(int akt_kierunek, int i, int j, int akt_idx){
    
    if (tab[i][j] != liczba[akt_idx]) return;
    if (akt_idx==3){
        ile ++;
        return;
    }

    int new_i = dy[akt_kierunek] + i;
    int new_j = dx[akt_kierunek] + j;

    if (new_i >=0 && new_i < n && new_j>=0 && new_j < m && layer[new_i][new_j] == layer[i][j]){
        solve(akt_kierunek, new_i, new_j, akt_idx+1);
    }

    if (akt_idx == 2) return;
    if (new_i >=0 && new_i < n && new_j>=0 && new_j < m && layer[new_i][new_j] == layer[i][j]){
        solve(( akt_kierunek + 1) % 4, new_i, new_j, akt_idx+1);
    }


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;

    
    while (q--){


        
        cin >> n >> m;
        ile = 0;

        for (int i=0; i<n; i++){
            
            string s;
            cin >> s;
            for (int j=0; j<m; j++){
                tab[i][j] = s[j]-'0';

                layer[i][j] = min(i,j,n - 1 - i,m - 1 - j);
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                for (int k=0; k<4; k++){
                    solve(k, i, j, 0);
                }
            }
        }
        
        cout << ile << endl;
    }


    return 0;
}
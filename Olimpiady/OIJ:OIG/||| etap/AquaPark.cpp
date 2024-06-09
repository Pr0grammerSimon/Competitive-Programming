#include <bits/stdc++.h>

using namespace std;

const int stala=2005;

vector<vector<unsigned long>> sum_pref(4009, vector<unsigned long>(4009));

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,y_1,x_1,len,up[2],down[2];
    cin >> n >> m;
    for (int y=0; y<n; y++){
        for (int x=0; x<n; x++){
            cin >> sum_pref[y-x+stala+1][y+x+stala+1];
        }
    }
    
    for (int y=1; y<4009; y++){
        for (int x=1; x<4009; x++){
            sum_pref[y][x] += sum_pref[y][x-1]+sum_pref[y-1][x]-sum_pref[y-1][x-1];
        }
    }
    for (int i=0; i<m; i++){
        cin >> y_1 >> x_1 >> len;
        y_1--;x_1--;
        down[0] = (y_1+len)-x_1+stala;
        down[1] = (y_1+len)+x_1+stala;
        up[0] = (y_1-len)-x_1+stala;
        up[1] = (y_1-len)+x_1+stala;

        cout << (long long)(sum_pref[down[0]+1][down[1]+1] - sum_pref[up[0]][down[1]+1] - sum_pref[down[0]+1][up[1]] + sum_pref[up[0]][up[1]])<<endl;
        
    }
    
}
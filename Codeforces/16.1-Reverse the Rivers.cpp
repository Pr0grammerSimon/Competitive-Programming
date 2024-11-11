#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, q;

    cin >> n >> m >> q;

    
    vector<vector<int>> grid(n+1,vector<int>(m+1,0));

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> grid[i][j];
            grid[i][j] |= grid[i-1][j];
        }
    }

    while (q--){
        int t;

        cin >> t;

        map<int,int> mini_m;
        map<int,int> maxi_m;


        int a, b;
        char c;


        set<int> secik;

        for (int i=0; i<t; i++){
            cin >> a >> c >> b;

            if (c == '<') maxi_m[a] = b - 1;
            else mini_m[a] = b + 1;

            secik.push(a);
        }

        int left = 1;

        int right = n;

        for (int r : secik){

            int mini = 1;
            int maxi = __INT_MAX__;


            if (mini_m.find(r) != mini_m.end()) mini = mini_m[r];
            if (maxi_m.find(r) != maxi_m.end()) maxi = maxi_m[r];

            int left_2 = left;
            int right_2 = right;

            while (left_2 < right_2){ //szukamy left
                int mid = (left_2 + right_2) / 2;

                if (grid[mid][r] < mini){
                    left_2 = mid + 1;
                }
                else{
                    right_2 = mid;
                }
            }

            left = max(left, left_2);
            left_2 = left;
            right_2 = right;


            while (left_2 < right_2){
                int mid = (left_2 + right_2) / 2;

                if (grid[mid][r] > mini){
                    right_2 = mid - 1;
                }
                else{
                    left_2 = mid;
                }
            }

            right = min(right, right_2);
            


        }

        cout << left << endl;



        
    }



    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;

    while (t--){
        int n;

        cin >> n;


        int  pop_val=0;

        bool git = true;

        for (int i=0; i<n; i++){
            int val;

            cin >> val;
            if (abs(val-pop_val) != 7 && abs(val-pop_val) != 5 && i!=0) git = false;
            pop_val = val;
        }



    

        if (git) cout << "YES\n";
        else cout << "NO\n";
    }



    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    int q;
    cin >> q;

    while (q--){
        cin >> s;

        vector<bool> jest(s.length());

        int ile=0;
        for (int i=0; i<s.length()-3; i++){
            jest[i] = false;
            if (s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0'){
                jest[i] = true;
                ile ++;
            }
        }

        int n;
        cin >> n;

        int idx;
        char c;

        for (int i=0; i<n; i++){
            cin >> idx >> c;
            idx--;

            for (int j=max(0, idx-3); j<min((idx+3), (int)s.length()-1); j++){
                ile -= jest[j];
                jest[j] = false;
                s[idx] = c;
                if (s[j] == '1' && s[j+1] == '1' && s[j+2] == '0' && s[j+3] == '0'){
                    jest[j] = true;
                    ile ++;
                }
            }

            if (ile > 0) cout << "YES\n";
            else cout << "NO\n";
        }

    }




    return 0;
}
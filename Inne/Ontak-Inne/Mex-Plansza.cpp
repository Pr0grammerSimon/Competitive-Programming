//kod do zilustrowania mex grida
#include <iostream>
#include <unordered_set>
#include <vector>


using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 10;
    vector<vector<int>> tab(n, vector<int>(n, 0));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<int> mexx;
            for (int k = 0; k < i; k++) mexx.push_back(tab[k][j]);
            for (int k = 0; k < j; k++) mexx.push_back(tab[i][k]);
            for (int k = 1; k <= min(i, j); k++) mexx.push_back(tab[i - k][j - k]);
            sort(mexx.begin(), mexx.end());

            for (int val : mexx) tab[i][j] += (val == tab[i][j]);
            cout << tab[i][j];
            int stala = max(int(log10(tab[i][j])), 0);
            for (int k = 0; k < 2 - stala; k++) cout << " ";
        }
        cout << '\n';
    }

    return 0;
}
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int k = (int)log2(n - 1) + 1;

    vector<bool> ustalone_bity(k);
    vector<bool> rozne_bity(k, 0);
    vector<bool> ustalone(k, 0);
    vector<bool> bity1(k, 0);
    vector<bool> bity2(k, 0);

    bool znaleziono_1 = 0;

    for (int bit = 0; bit < k; bit++) {
        cout << "? ";
        for (int i = 0; i < n; i++) {
            if ((1 << bit) & i) cout << 1;
            else cout << 0;
        }
        cout << endl;

        int odp;
        cin >> odp;
        if (odp % 2) {
            if (!znaleziono_1) {
                znaleziono_1 = 1;
                ustalone[bit] = 1;
                bity1[bit] = 1;
            }
            rozne_bity[bit] = 1;
        }
    }

    for (int bit = 0; bit < k; bit++) {
        if (ustalone[bit]) continue;
        ustalone[bit] = 1;
        bity1[bit] = 1;

        cout << "? ";
        for (int i = 0; i < n; i++) {
            bool git = 1;

            for (int bit2 = 0; bit2 < k; bit2++) {
                if (!ustalone[bit2]) continue;
                bool czy_jest = (1 << bit2) & i;
                if (czy_jest != bity1[bit2]) git = 0;
            } 

            if (git) cout << 1;
            else cout << 0;
        }
        cout << endl;

        int odp;
        cin >> odp;
        odp %= 2;


        if (rozne_bity[bit]) {
            if (!odp) {
                bity1[bit] = 0;
                bity2[bit] = 1;
            }
        }
        else {
            if (!odp) {
                bity1[bit] = 0;
                bity2[bit] = 0;
            }
            else{
                bity2[bit] = 1;
            }
        }

    }

    int odp1 = 0, odp2 = 0;

    for (int i = 0; i < k; i++) odp1 += (1 << i) * bity1[i];
    for (int i = 0; i < k; i++) odp2 += (1 << i) * bity2[i];

    cout << "! " << odp1 << ' ' << odp2 << endl;



    return 0;
}
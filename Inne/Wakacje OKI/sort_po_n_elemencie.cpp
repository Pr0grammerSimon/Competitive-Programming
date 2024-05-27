#include <bits/stdc++.h>
using namespace std;

int a_,b_,c_;
bool is_lower(int &a[], int &b[]){
    if (a[a_] > b[a_]) return true;
    if (a[a_] < b[a_]) return false;
    if (a[b_] > b[b_]) return false;
    if (a[b_] < b[b_]) return false;
    if (a[c_] > b[c_]) return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    int x[n][3];
    for(int i=0;i<n;i++){
        cin>>int[i][0]>>int[i][1]>>int[i][1];
    }
    cin >> a_ >> b_ >> c_;
    sort(x, x+n, is_lower);
    for(int i=0;i<n;i++){
        for (int j:x[i]){
            cout << j << " " << endl;
        }
    }
}
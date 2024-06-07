#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int liczby_1[1000000];
    int liczby_2[1000000];
    int wynik;
    for (int i=0; i<n; i++){
        cin >> liczby_1[i];
    }
    for (int i=0; i<n; i++){
        cin >> liczby_2[i];
        if (liczby_2[i] < liczby_1[i]) wynik ++;
    }
    cout << wynik;
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long ilosc_liczb,mini,mid,idx,wynik;
long long liczby[ (int)1e6+7], sumy[ (int)1e6+7 ];
int binary_search(int l,int p,long long val){
    //cout << "UWU" << l << p << val << endl;
    while (l < p){
        //cout << l << p << mid << val << endl;
        mid = (l+p) / 2;
        if (liczby[mid] < val){
            l = mid+1;
        } 
        else{
            p = mid;
        }
    }
    //cout << l << p << val << endl;
    return l;
}

int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> ilosc_liczb >> mini;
    for (int i=0; i<ilosc_liczb; i++){
        cin >> liczby[i];
    }
    
    sort(liczby,liczby+ilosc_liczb);
    sumy[0] = 0;
    for (int i=0; i<ilosc_liczb; i++){
        sumy[i+1] = sumy[i] + liczby[i];
    }
    for (int i=0; i<ilosc_liczb; i++){
        if (i==ilosc_liczb-1){continue;}
        else if (liczby[i]+mini > liczby[ilosc_liczb-1]){
            //cout << "UWU1" << endl;
            wynik += (ilosc_liczb-1-i)*mini;
        }
        else{
            //cout << "UWU" << endl;
            idx = binary_search(i+1,ilosc_liczb-1,liczby[i]+mini);
            wynik += (idx-i-1) * mini;
            //cout << "WYNIK: " << wynik << endl;
            wynik += (sumy[ilosc_liczb]-sumy[idx]) - (ilosc_liczb-idx)*liczby[i];
        }
        //cout << wynik << " " << sumy[i+1] << " " << liczby[i] << " " << i << " " <<endl;
    }
    
    cout << wynik;
    
    return 0;
}
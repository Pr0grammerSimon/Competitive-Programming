#include <bits/stdc++.h>

using namespace std;

const int MAXN=1000007;
int wynik;


struct punkt{
    int idx,val;
};



int main(){
    int n,info;
    punkt punkcik;
    cin >> n;
    
    stack<punkt> stos;
    
    for (int i=0; i<n; i++){
        punkcik.idx=i;
        cin >> info;
        punkcik.val = info;
        
        if (stos.size()>0){
            if (stos.top().val > 0 && info<0 && stos.top().val==abs(info) ){
                stos.pop();
            }
            else{
                stos.push(punkcik);
            }
        }
        else{
            stos.push(punkcik);
        }
        
    }
    int ostatni=n,ost=0;
    while (stos.size()>0){

        wynik = max(wynik,ostatni-stos.top().idx-1);
        ostatni=stos.top().idx;
        ost=stos.top().idx;
        stos.pop();
        
    }
    wynik = max(wynik, ost);
    cout << wynik;
    return 0;
    
    
}
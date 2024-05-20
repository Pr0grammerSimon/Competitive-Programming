#include <bits/stdc++.h>
using namespace std;
 
const int base = 2<<18;
int tree[base*2+7];
 
void edit(int n){
    n+=base;
    while (n>0){
        tree[n] += 1;
        n/=2;
    }
}
 
int query(int a,int b){
    a+=base-1;
    b+=base+1;
    int wynik=0;
    while (a/2 != b/2){
        if (a%2==0) wynik += tree[a+1];
        if (b%2==1) wynik += tree[b-1];
        a/=2;
        b/=2;
    }
    return wynik;
}
 
 
long unsigned int count_swaps(vector<int>S){
    long long wynik = 0,len=S.size(),idx_1=0,akt_liczba=0,idx_2=0,idx_3=0;
    pair< vector<int>,int> idx[200007];
    int base_2 = 100001;
    for (int i=0; i<S.size(); i++){
        idx[S[i]+base_2].first.push_back(i);
    }
    
    vector<pair<int,int>> stos(0);
    bool uzyte[200007];
    //Zerujemy 
    for (int i=0; i<200007; i++) uzyte[i] = false;
    
    for (int i=0; i<S.size(); i++){
        if (!uzyte[i]){
            idx_1 = i;
            idx_2 = idx[(-S[i])+base_2].first[idx[(-S[i])+base_2].second];
            idx[(-S[i])+base_2].second += 1;
            idx[S[i]+base_2].second +=1;
            uzyte[idx_1] = true;
            uzyte[idx_2] = true;
            if (S[idx_2] < S[idx_1]) swap(idx_1,idx_2);
            stos.push_back({idx_1,idx_2});
        }
    }
    
    for (int i=0; i<stos.size(); i++){
        
        idx_2=stos[i].first;
        wynik += idx_2-(i*2)+query(idx_2+1,len);
        edit(idx_2);
        
        idx_3 = stos[i].second;
        wynik += idx_3-((i*2)+1)+query(idx_3+1,len);
        edit(idx_3);

    }
    for (int j=0; j<base*2+7; j++){
        tree[j] = 0;
    }
 
    return wynik;
}
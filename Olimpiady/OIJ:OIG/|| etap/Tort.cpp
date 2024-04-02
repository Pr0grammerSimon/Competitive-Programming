#include <bits/stdc++.h>
using namespace std;

constexpr int M =2e5+7;
long long h[M];
long long v[M];
int n;

long long count(long long val){
    long long res = 0;
    int x = 0;
    for (int y=n; y>=0; y--){
        while (x <= n && h[x]*v[y]<val) x++;
        
        res += n-x+1;
    }
    return res;
}


long long bin(long long K){
    long long p,k,mid;
    
    p=h[0]*v[0];
    k=h[n]*v[n];
    while (p<k){
        mid = (p+k+1) / 2;
        if (count(mid)<K) k=mid-1;
        else p=mid;
    }
    return p;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long a,b,k,prev,x;
    cin >> a >> b >> n >> k;
    
    prev=0;
    for (int i=0; i<n; i++){
        cin >> x;
        h[i] = x-prev;
        prev = x;
    }
    h[n] = a-prev;
    
    prev=0;
    for (int i=0; i<n; i++){
        cin >> x;
        v[i] = x-prev;
        prev = x;
    }
    v[n] = b-prev;
    
    sort(h,h+n+1);
    sort(v,v+n+1);
    
    cout << bin(k);
    return 0;
}
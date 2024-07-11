#include <bits/stdc++.h>

using namespace std;


const int base = 1<<19;
const int stala=200007;
int tree[base*2];
int lazy[base*2];


void push_(int v){
    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];
    tree[2*v+1] += lazy[v];
    tree[2*v] += lazy[v];
    lazy[v]=0;
}


int query(int v, int pq, int kq, int p, int k){
    
    if (p>=pq && k <= kq) return tree[v];
    else if (k<pq || p>kq) return 0;
    else{
        int mid = (p+k)/2;
        push_(v);
        return max(query(v*2,pq,kq,p,mid),query(v*2+1,pq,kq,mid+1,k));
        
    }
    

}

void edit(int v, int pq, int kq, int p, int k, int val){
    
    if (p>=pq && k <= kq) {tree[v]+=val; lazy[v]+=val;}
    else if (k<pq || p>kq) return;
    else{
        int mid = (p+k)/2;
        push_(v);
        edit(v*2,pq,kq,p,mid,val);
        edit(v*2+1,pq,kq,mid+1,k,val);
        tree[v] = max(tree[v*2],tree[v*2+1]);
    }
}


struct punkt{
    int y_1,y_2,x;
};


bool compare_(punkt &p_1, punkt &p_2){
    return (p_1.x<p_2.x);
}


int main(){
    ios_base::sync_with_stdio();cin.tie(0);cout.tie(0);
    
    
    int n,x_1,y_1,x_2,y_2; cin >> n;
    
    vector<punkt> punkty_otwarte(0);
    vector<punkt> punkty_zamkniete(0);
    punkt dodatkowe;
    
    for (int i=0; i<n; i++){
        cin >> x_1 >> y_1 >> x_2 >> y_2;
    
        dodatkowe.x = x_1; dodatkowe.y_1 = y_1; dodatkowe.y_2 = y_2;

        punkty_otwarte.push_back({dodatkowe}); // dodawanie na przedziale
        
        dodatkowe.x = x_2;
        
        punkty_zamkniete.push_back({dodatkowe}); // usuwanie na przedziale
        
    }
    
 
    
    sort(punkty_otwarte.begin(),punkty_otwarte.end(),compare_);
    sort(punkty_zamkniete.begin(),punkty_zamkniete.end(),compare_);
    
    int maxi = 0;
    int akt_o=0;
    int akt_z=0;
    for (int i=-200000; i<200000; i++){
        while (akt_o < punkty_otwarte.size() && punkty_otwarte[akt_o].x==i){
            edit(1,punkty_otwarte[akt_o].y_1+stala,punkty_otwarte[akt_o].y_2+stala,0,base-1,1);
            akt_o++;
        }
        //cout << tree[1]<<endl;
        maxi = max(maxi,tree[1]);
        while (akt_z < punkty_zamkniete.size() && punkty_zamkniete[akt_z].x==i){
            edit(1,punkty_zamkniete[akt_z].y_1+stala,punkty_zamkniete[akt_z].y_2+stala,0,base-1,-1);
            akt_z++;
        }
    }
    cout << maxi << endl;
    
    return 0;
}
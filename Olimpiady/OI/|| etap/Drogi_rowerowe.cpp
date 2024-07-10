/*
Krotki opis rozwiazania

Wyznaczamy silne spojne skladowe, a potem je laczymy dzieki FAU/DSU (inne nazewnictwo)
Gdy mamy juz graf acykliczny dzieki polaczeniu w jednen wierzcholek cykle,
robimy graf transponowany i sortowaniem topologicznym w odpowiedzniej kolejnosci przechodzimy po wierzcholkach i mamy wynik

*/


#include <bits/stdc++.h>

using namespace std;


const int MAXN = 50007;

bool odwiedzone[MAXN];

int ile[MAXN];



vector<int> graf[MAXN];
vector<int> graf_2[MAXN];


stack<int> stos;


int rep[MAXN];

int find(int a){
    if (a != rep[a]){
        rep[a] = find(rep[a]);
    }
    return rep[a];
}


void union_(int a, int b){
        int a_ = find(a);
        int b_ = find(b);
    if (a_!=b_){
        ile[a_]+=ile[b_];
        rep[b_]=rep[a_];
    }
    
}



void dfs(int v){
    odwiedzone[v] = true;    
    for (auto i : graf[v]){
        if (!odwiedzone[i]){
            dfs(i);
        }
    }
    
    stos.push(v);

}

void dfs2(int v, int spojna){
    odwiedzone[v] = true;
    
    union_(v,spojna);
    
    for (auto i:graf_2[v]){
        if (!odwiedzone[i]){
            dfs2(i,spojna);
        }
    }
    
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    int n,m,a,b;
    cin >> n >> m;
    
    
    for (int i=0; i<m; i++){
        cin >> a >> b;
        graf[a].push_back(b);
        graf_2[b].push_back(a);
    }
    
    for (int i=1; i<=n; i++){
        if (!odwiedzone[i]) dfs(i);
        rep[i]=i;
        ile[i]=1;
        
    }
    
    for (int i=0; i<=n; i++) odwiedzone[i] = false;
    
    
    int akt_spojna = 1;
    
    
    while (!stos.empty()){
        
        if (!odwiedzone[stos.top()]){
            dfs2(stos.top(),stos.top());
            akt_spojna ++;
        }
        
        stos.pop();
    }
   
    vector<vector<int>> graf_spojnych(MAXN+1,vector<int>());
    
    vector<int> ile_wchodzacych_spojnych(MAXN+1,0);
    
    for (int v=1; v<=n; v++){
        int spojna_1 = find(v);
        
        for (auto sasiad : graf[v]){
            int spojna_2 = find(sasiad);
          
            if (spojna_1!=spojna_2){
                ile_wchodzacych_spojnych[spojna_1]+=1;
                graf_spojnych[spojna_2].push_back(spojna_1);
            }
        }
    }
    
    vector<bool> odwiedzone_spojne(MAXN+1,0);
    vector<int>  wyniki_spojne(MAXN+1,1);
    stack<int> stos_topologiczny;
    
    
    for (int v=1; v<=n; v++){
        
        wyniki_spojne[find(v)] = ile[find(v)];
        if (!odwiedzone_spojne[find(v)] && ile_wchodzacych_spojnych[find(v)]==0){
            odwiedzone_spojne[find(v)]=true;
            
            stos_topologiczny.push(find(v));
           
        }
    }
   
    while(!stos_topologiczny.empty()){
       
        int spojna_v = stos_topologiczny.top();
        stos_topologiczny.pop();
        for (auto i : graf_spojnych[spojna_v]){
           
            ile_wchodzacych_spojnych[i]-=1;
  
            wyniki_spojne[i]+=wyniki_spojne[spojna_v];
            if (ile_wchodzacych_spojnych[i]==0) stos_topologiczny.push(i);
        }
        
      
    }
    
    
    for (int i=1; i<=n; i++) cout << wyniki_spojne[find(i)]-1 << endl;
    
    
    return 0;
}
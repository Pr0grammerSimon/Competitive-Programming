#include <bits/stdc++.h>

using namespace std;

struct bohater{
    string imie;
    long dmg;
    long hp;
};

bool check(bohater &b_1, bohater &b_2){
    if (b_1.imie < b_2.imie) return true;
    if (b_2.imie < b_1.imie) return false;
    if (b_1.hp < b_2.hp) return true;
    if (b_2.hp < b_1.hp) return false;
    return (b_1.dmg < b_2.dmg);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m,akt_potwor;
    cin >> n;
    queue<bohater> kolejka;

    for (int i=0; i<n; i++){
        bohater akt_bohater;
        cin >> akt_bohater.imie >> akt_bohater.hp >> akt_bohater.dmg;
        kolejka.push(akt_bohater);
    }
    cin >> m;
  
    long long potwor[m][2];
    for (int i=0; i<m; i++){
        cin >> potwor[i][0] >> potwor[i][1];
    }
    
    bohater akt_gracze[3];
    long akt_suma;
    for (int i=0; i<3; i++){
        kolejka.push(bohater {"bot",0,0});
        akt_gracze[i] = kolejka.front();
        kolejka.pop();
        
    }
  
    while (akt_potwor < m){
        akt_suma = 0;
        for (auto i:akt_gracze){
            if (i.hp > 0) akt_suma += i.dmg;
        }
        potwor[akt_potwor][0] -= akt_suma;
        if (potwor[akt_potwor][0] <= 0) akt_potwor += 1;
        else{
            for (auto &i:akt_gracze){
                if (i.imie != "bot"){
                    i.hp -= potwor[akt_potwor][1];
                    if (i.hp <= 0){
                        i = kolejka.front();
                        kolejka.pop();
                    }
                }
            }
        }
    }
    
    vector<bohater> pozostali(0);
    for (auto i: akt_gracze){
        if (i.hp>0) pozostali.push_back(i);
       
    
    }
    while (!kolejka.empty()){
        if (kolejka.front().hp > 0) pozostali.push_back(kolejka.front());
        kolejka.pop();
    }
    sort(pozostali.begin(),pozostali.end(),check);
    for (auto i: pozostali){
        cout << i.imie<< " " << i.hp << ' ' << i.dmg << '\n';
    }
    
}
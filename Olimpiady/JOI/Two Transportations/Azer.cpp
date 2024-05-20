#include <bits/stdc++.h>
#include "Azer.h"
 
using namespace std;
 
namespace{
const int MAXN = 99999999;
int suma = 0;
pair <int,int> akt_top;
int akt = 0;
int akt_2 = 0;
int akt_bits = 9;
string akt_str = "";
vector<int> answer={0};
int info[2];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
vector<vector<pair<int,int>>> graf(500000);
 
string decToBinary(int n,int bits)
{
    string ans = "";
    for (int i = bits; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            ans += "1";
        else
            ans += "0";
    }
    return ans;
}
 
int binaryToDecimal(string str)
{
    int dec_num = 0;
    int power = 0 ;
    int n = str.length() ;
 
      for(int i = n-1 ; i>=0 ; i--){
      if(str[i] == '1'){
        dec_num += (1<<power) ;
      }
      power++ ;
    }
 
    return dec_num;
}
 
void send(int a,int bits){
    bits--;
    string bin = decToBinary(a,bits);
    //cout << "WYSYLA A: " << a << " z tyloma bitami: " << bits << " " << bin <<  endl;
    for (int i=0; i<bits+1; i++){
        SendA(bin[i]-'0');
    }
}
}
 
void ReceiveA(bool x){
    if (x == 0) akt_str += "0";
    else akt_str += "1";
 
    if (akt_2==akt_bits-1){
        int liczba = binaryToDecimal(akt_str);
        //cout << "otrzymal A: " << liczba << " akt bity: " << akt_bits << " str "<< akt_str <<endl;
        if (akt==0){ // wartosc
            info[0] = liczba;
            while (pq.top().first != MAXN && answer[pq.top().second] <= pq.top().first) {
                    pq.pop();
            }
 
            if (pq.empty()) pq.push({MAXN,2024});
            akt_top = pq.top();
            if (min(akt_top.first-suma,507)==507 && info[0]==507) return;
            send(min(akt_top.first-suma,507),9);
            if (akt_top.first-suma < info[0]){
                suma = akt_top.first;
                send(akt_top.second,11);
                pq.pop();
                answer[akt_top.second] = akt_top.first;
                //cout << "A WYBRANY: " << akt_top.first<<endl;
                //// DIJKSTRA
                for (auto [a,val] : graf[akt_top.second]){
                    if (answer[a] > akt_top.first+val){
                        pq.push({akt_top.first+val,a});
                    }
                }
                //for (auto i : answer) cout << i << " ";
                //    cout << endl;
                akt_bits = 9;
            }
            else{
                akt = 1;
                akt_bits = 11;
            }
        }
        else if(akt==1){ // Wierzcholek
            info[1] = liczba;
            suma += info[0];
            answer[info[1]] = suma;
            //cout << "A WYBRANY: " << info[0]<<endl;
            for (auto [a,val] : graf[info[1]]){
                if (answer[a] > suma+val){
                    pq.push({suma+val,a});
                }
            }
            //for (auto i : answer) cout << i << " ";
            //cout << endl;
            akt = 0;
            akt_bits = 9;
        }
        akt_2 = 0;
        akt_str = "";
    }
    else akt_2 += 1;
}
 
 
 
void InitA(int N, int A, vector<int> U, vector<int> V, vector<int> C){
    for (int i=1; i<N; i++){
        answer.push_back(9999999);
    }
    for (int i=0; i<A; i++){
        graf[U[i]].push_back({V[i],C[i]});
        graf[V[i]].push_back({U[i],C[i]});
    }
    for (auto [a,val] : graf[0]){
        pq.push({val,a});
    }
    pq.push({MAXN,2024});
 
}
 
vector<int> Answer(){
    return answer;
}
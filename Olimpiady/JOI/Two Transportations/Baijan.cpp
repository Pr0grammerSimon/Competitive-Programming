#include <bits/stdc++.h>
#include "Baijan.h"
using namespace std;
 
namespace{
int n;
int liczba_odw = 0;
const int MAXN = 99999999;
int suma = 0;
pair <int,int> akt_top;
int akt = 0,akt_2=0,akt_bits=9;
int info[2];
string akt_str="";
vector<int> answer={0};
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
        //cout << "WYSYLA B: " << a << " z tyloma bitami: " << bits << " " << bin << endl;
    for (int i=0; i<bits+1; i++){
        SendB(bin[i]-'0');
    }
}
}
void ReceiveB(bool y){
    if (y == 0) akt_str += "0";
    else akt_str += "1";
   
    if (akt_2==akt_bits-1){
        int liczba = binaryToDecimal(akt_str);
        //cout << "otrzymal B: " << liczba << " akt bity: " << akt_bits << " str "<< akt_str <<endl;
        if (akt==0){ // wartosc
            info[0] = liczba;
            
            while (pq.top().first != MAXN && answer[pq.top().second] <= pq.top().first) pq.pop();
            if (pq.empty()) pq.push({MAXN,2024});
            akt_top = pq.top();
            if (min(akt_top.first-suma,507)==507 && info[0]==507) return;
            
            if (akt_top.first-suma <= info[0]){
                liczba_odw ++;
                suma = akt_top.first;
                send(akt_top.second,11);
                pq.pop();
                answer[akt_top.second] = akt_top.first;
                //cout << "B WYBRANY: " << akt_top.first << " " << akt_top.second <<endl;
                //// DIJKSTRA
                
                for (auto [a,val] : graf[akt_top.second]){
                    
                    if (answer[a] > akt_top.first+val){
                        pq.push({akt_top.first+val,a});
                    }
                }
 
                akt_bits = 9;
                while (pq.top().first != MAXN && answer[pq.top().second] <= pq.top().first) {
                        pq.pop();
                }

                //for (auto i : answer) cout << i << " ";
                //cout << endl;
                if (pq.empty()) pq.push({MAXN,2024});
                if (liczba_odw==n) return;
                send(min(pq.top().first-suma,507),9);
            }
            else{
                akt = 1;
                akt_bits = 11;
            }
        }
        else if(akt==1){ // Wierzcholek
            liczba_odw ++;
            info[1] = liczba;
            suma += info[0];
            answer[info[1]] = suma;
            //cout << "B WYBRANY: " << info[0]<<endl;
            for (auto [a,val] : graf[info[1]]){
                if (answer[a] > suma+val){
                    pq.push({suma+val,a});
                }
            }
            //for (auto i : answer) cout << i << " ";
            //cout << endl;
            akt = 0;
            akt_bits = 9;
            while (pq.top().first != MAXN && answer[pq.top().second] <= pq.top().first) pq.pop();
            if (pq.empty()) pq.push({MAXN,2024});
            if (liczba_odw==n) return;
            send(min(pq.top().first-suma,507),9);
        }
        akt_2 = 0;
        akt_str = "";
    }
    else akt_2 += 1;
}
 
void SendB(bool x);
 
void InitB(int N, int B, std::vector<int> S, std::vector<int> T, std::vector<int> D){
    n = N;
    for (int i=1; i<N; i++){
        answer.push_back(9999999);
    }
    for (int i=0; i<B; i++){
        graf[S[i]].push_back({T[i],D[i]});
        graf[T[i]].push_back({S[i],D[i]});
    }
    for (auto [a,val] : graf[0]){
        pq.push({val,a});
    }
    pq.push({MAXN,2024});
    liczba_odw ++;
    send(min(pq.top().first,507),9);
 
}
#include <bits/stdc++.h>
using namespace std;


int ilosc_liter_w_slowie[10000][26];

int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    char literki[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int ilosc_slow;
    cin >> ilosc_slow;
    
    string slowa[ilosc_slow];
    int mini_idx[ilosc_slow];

    
    for (int i=0; i<ilosc_slow; i++){
        cin >> slowa[i];
        mini_idx[i] = 0;
        for (char c : slowa[i]){
            ilosc_liter_w_slowie[i][c-'a'] ++;
        }
       
    }
    
    
    string wynik="";
    
    
    for (int c=25; c>=0; c--){
        
        

        
        int mini_ilosc=1e9;
        
        for (int i=0; i<ilosc_slow; i++){
            int ilosc_w_tym_slowie=0;
            
            mini_ilosc = min(mini_ilosc,ilosc_liter_w_slowie[i][c]);
            
        }
        
        
        if (mini_ilosc>0){
            for (int i=0; i<ilosc_slow; i++){
                int akt_ilosc=0;

                for (int j=mini_idx[i]; j<slowa[i].length(); j++){
                    ilosc_liter_w_slowie[i][slowa[i][j]-'a']--;
                    if (slowa[i][j]==literki[c]){
                        akt_ilosc++;
                        if (akt_ilosc==mini_ilosc){
                            mini_idx[i]=j;
                            break;
                        }
                    }
                }
                
                
            }
        }
        
        for (int i=0; i<mini_ilosc; i++) wynik += literki[c];
        

    }
    
    if (wynik < "bitek") wynik="bitek";
    cout << wynik << endl;

    return 0;
}
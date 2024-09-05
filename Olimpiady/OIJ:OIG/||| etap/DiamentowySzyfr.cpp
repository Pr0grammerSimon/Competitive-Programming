#include <bits/stdc++.h>

using namespace std;

int reszta_z_3(vector<int> a){
    int suma=0;
    
    for (auto i : a) suma += i;
    
    return (suma%3);
}


vector<int> podziel_przez_3(vector<int> a){
    int akt_liczba=a[0];
    
    vector<int> wynik;
    
    for (int i=0; i<a.size(); i++){
        wynik.push_back(akt_liczba/3);
        
        akt_liczba %=3;
        
        if (i+1 < a.size()){
            akt_liczba = (akt_liczba)*10 + a[i+1];
        }
        
    }
    
    
    return wynik;
}




int main()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        string wejscie;
        cin >> wejscie;
        
        vector<int> liczby;
        
        for (char j: wejscie){
            liczby.push_back(j-'0');
        }
        
        
        vector<int> trojkowo;
        
        bool warunek = true;
        while (warunek){
            trojkowo.push_back(reszta_z_3(liczby));
            liczby = podziel_przez_3(liczby);
            
            warunek = false;
            for (auto j : liczby){
                if (j!=0){
                    warunek = true;
                    break;
                }
            }
        
        }
        
        vector<int> zapalone;
        vector<int> zgaszone;
        
        
        for (int j=0; j<trojkowo.size(); j++){
            if (trojkowo[j]==1){
                zapalone.push_back(j);
            }
            else if (trojkowo[j]==2){
                trojkowo[j]=-1;
                zgaszone.push_back(j);
                
                if (trojkowo.size()<=j+1) trojkowo.push_back(1);
                else trojkowo[j+1] ++;
            }
            else if (trojkowo[j]==3){
                trojkowo[j] = 0;
                if (trojkowo.size()<=j+1) trojkowo.push_back(1);
                else trojkowo[j+1] ++;
            }
        }
        
        cout<<zapalone.size() << " ";
        for (auto j : zapalone) cout << j << " ";
        cout << endl;
        cout << zgaszone.size()<<" ";
        for (auto j : zgaszone) cout << j << " ";
        cout << endl;
        
        
        
    }
    
    
    return 0;
}
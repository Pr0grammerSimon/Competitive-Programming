//Rozwiązanie polega na generowaniu mozliwych kolejnych liczb skracalnych pierwszych z juz istniejacych, gdyz takich liczb jest malo


#include <bits/stdc++.h>

using namespace std;


bool czy_pierwsza(long long liczba){
    for (int i=2; ((long long)i*i)<=liczba; i++){
        if ((liczba%i)==0) return false;
    }
    return true;
}


int main(){
    
    priority_queue<long long> kolejka;
    
    for (int i=2; i<=7; i++){
        if (czy_pierwsza(i)) kolejka.push(-i);
    }
    
    
    int wynik=0;
    
    
    long long a,b;
    cin >> a >> b;
    
    while (!kolejka.empty() && -(kolejka.top())<=b){
        long long liczba = -kolejka.top();
        kolejka.pop();

        if (liczba>=a && liczba<=b) wynik++;
        
        for (int i=1; i<10; i++){
            if (czy_pierwsza((long long)(liczba*10)+i)) kolejka.push(-((long long)(liczba*10)+i));
        }
        
    }
    
    cout << wynik << endl;
    
    
    return 0;
}
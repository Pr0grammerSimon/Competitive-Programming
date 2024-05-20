#include <string>
#include <iostream>
using namespace std;
 
const int MAXN = 100007;
int ilosc_a_t[MAXN];
int ilosc_a_c[MAXN];
int ilosc_t_c[MAXN];
int ilosc_t_a[MAXN];
int ilosc_c_a[MAXN];
int ilosc_c_t[MAXN];
 
void init(string a, string b){
    if (a[0] == 'A'){
        if (b[0] == 'C') ilosc_a_c[0] = 1;
       else if (b[0] == 'T') ilosc_a_t[0] = 1;
    }
    else if (a[0]=='C'){
        if (b[0] == 'A') ilosc_c_a[0] = 1;
        else if (b[0] == 'T') ilosc_c_t[0] = 1;
    }
    else{ // T
        if (b[0] == 'C') ilosc_t_c[0] = 1;
        else if (b[0] == 'A') ilosc_t_a[0] = 1;
    }
 
 
    for (int i=1; i<a.length(); i++){
        ilosc_a_c[i]=ilosc_a_c[i-1]; ilosc_a_t[i]=ilosc_a_t[i-1]; ilosc_c_a[i]=ilosc_c_a[i-1]; ilosc_c_t[i]=ilosc_c_t[i-1];ilosc_t_a[i]=ilosc_t_a[i-1]; ilosc_t_c[i]=ilosc_t_c[i-1];
        if (a[i] == 'A'){
            if (b[i] == 'C') ilosc_a_c[i] = ilosc_a_c[i-1]+1;
            else if (b[i] == 'T') ilosc_a_t[i] = ilosc_a_t[i-1] + 1;
        }
        else if (a[i]=='C'){
            if (b[i] == 'A') ilosc_c_a[i] = ilosc_c_a[i-1]+1;
            else if (b[i] == 'T') ilosc_c_t[i] = ilosc_c_t[i-1] + 1;
        }
        else{ // T
            if (b[i] == 'C') ilosc_t_c[i] = ilosc_t_c[i-1]+1;
            else if (b[i] == 'A') ilosc_t_a[i] = ilosc_t_a[i-1] + 1;
        }
    }
    
}
 
int get_distance(int x, int y){
    int i_a_t = ilosc_a_t[y]-ilosc_a_t[x-1];
    int i_a_c = ilosc_a_c[y]-ilosc_a_c[x-1];
    int i_t_c = ilosc_t_c[y]-ilosc_t_c[x-1];
    int i_t_a = ilosc_t_a[y]-ilosc_t_a[x-1];
    int i_c_a = ilosc_c_a[y]-ilosc_c_a[x-1];
    int i_c_t = ilosc_c_t[y]-ilosc_c_t[x-1];

    if ((i_a_c+i_a_t)!=(i_t_a+i_c_a) || (i_t_c+i_t_a) != (i_c_t+i_a_t) || (i_c_a+i_c_t) != (i_a_c+i_t_c)) return -1;
    
 
    int c_t = min(i_c_t,i_t_c);
    int a_t = min(i_a_t,i_t_a);
    int c_a = min(i_a_c,i_c_a);
    i_c_a -= c_a;
    i_a_c -= c_a;
    i_t_c -= c_t;
    i_c_t -= c_t;
    i_a_t -= a_t;
    i_t_a -= a_t;
    
    long long wynik = (((i_c_a+i_a_c+i_t_c+i_c_t+i_a_t+i_t_a)/3)*2)+c_t+a_t+c_a;
    return wynik;
 
 
}
 
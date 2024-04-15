#include<iostream>

using namespace std;

int main() {

    long long int n, r;
    bool warunek = true;
    cin>>n;

    if(n<10) {
        cout<<9<<endl;
    }
    else if(n<20) {
        cout<<18<<endl;
    }
    else {
        
        for(int i=0; i<10; i++) {
            n = n - n%10;
            n += i;
            if(n%9 == 0) {
                i=10;
                cout<<n<<endl;
            } 
        }
        
    }
    return 0;
}
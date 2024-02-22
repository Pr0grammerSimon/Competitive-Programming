ilosc_testow = int(input())
for i in range(ilosc_testow):
    liczba = int(input())
    liczba_bin_1 = bin(2*liczba-1)
    if liczba_bin_1.count('1') % 2 == 0:
        print(2*liczba-1)
    else:
        print(2*liczba-2)
""" C++ 100%
#include <iostream>
using namespace std;

int dec_to_bin(int liczba)
{
	int i=0,tab[31];

	while(liczba) //dopóki liczba będzie różna od zera
	{
		tab[i++]=liczba%2;
		liczba/=2;
	}
    int licznik = 0;
	for(int j=i-1;j>=0;j--)
	    if (tab[j] == 1){
		licznik ++;
	    }
	return licznik;
}

int main()
{   
    int testy = 0;
    cin >> testy;
	int liczba = 0;
	for (int i=0; i < testy; i++){
	cin>>liczba;
	if ( dec_to_bin(liczba*2-1) % 2 == 0){
	    cout << liczba*2-1;
	}
	else{
	    cout << liczba*2-2;
	}
	cout << endl;
	}
	return 0;
}

"""
ilosc_liczb = int(input())
wyniki = [0 for i in range(1,ilosc_liczb+2)]
liczby = input().split()
ilosc_testow = int(input())

akt_liczba = -1
akt_wynik = 0
for i in liczby:
    i = int(i)
    if i > akt_liczba:
        akt_wynik += 1
    else:
        for j in range(1,akt_wynik+1):
            wyniki[j] += akt_wynik - j + 1
        akt_wynik = 1
    akt_liczba = i
for i in range(1,akt_wynik+1):
    wyniki[i] += akt_wynik - i + 1

for i in range(ilosc_testow):
    print(wyniki[int(input())])
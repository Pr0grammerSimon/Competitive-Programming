ilosc_liczb = int(input())
liczby = [int(i) for i in input().split()]

left = 0
right = 0
wynik = 0
akt_wynik = 1
akt_ilosc = 0
while left < ilosc_liczb and right < ilosc_liczb:
    #print(wynik,akt_wynik,left,right)
    if (akt_wynik*liczby[right]) < 1000000:
        akt_wynik *= liczby[right]
        akt_ilosc += 1
        wynik += akt_ilosc
        right += 2
    else:
        akt_wynik /= liczby[left]
        left += 2
        akt_ilosc -= 1
    if left > right:
        right = left
    #if akt_ilosc < 0:
    #    akt_ilosc = 0

left = 1
right = 1
akt_wynik = 1
akt_ilosc = 0
while left < ilosc_liczb and right < ilosc_liczb:
    #print(wynik,akt_wynik,left,right)
    if (akt_wynik*liczby[right]) < 1000000:
        akt_wynik *= liczby[right]
        akt_ilosc += 1
        wynik += akt_ilosc
        right += 2
    else:
        akt_wynik /= liczby[left]
        left += 2
        akt_ilosc -= 1
    if left > right:
        right = left
    #if akt_ilosc < 0:
    #    akt_ilosc = 0

print(wynik)


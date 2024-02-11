ilosc_kom = int(input())
komorki = [int(i) for i in input().split()]
komorki.sort()

wskaznik = 0
mozliwe_komorki = []
akt_wzrost = 2
licznik = 0
while wskaznik < ilosc_kom:
    if akt_wzrost >= komorki[-1]: break
    if komorki[wskaznik] < akt_wzrost:
        mozliwe_komorki.append(komorki[wskaznik])
        wskaznik += 1
    elif len(mozliwe_komorki) > 0:
        akt_wzrost += mozliwe_komorki[-1]
        mozliwe_komorki.pop()
        licznik += 1 
    else:
        break

if akt_wzrost >= komorki[-1]:
    print(licznik)
else:
    print('NIE')
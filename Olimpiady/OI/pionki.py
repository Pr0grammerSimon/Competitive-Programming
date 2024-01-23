wysokosc,szerokosc = input().split()

tablica = []
for i in range(int(wysokosc)):
    tablica.append(input())


licznik_wysokosc = {0:0}
licznik_szerokosc = {0:0}
liczba_pionkow = 0
for i in range(int(wysokosc)):
    for j in range(int(szerokosc)):
        if tablica[i][j] == '#':
            liczba_pionkow += 1
            if i in licznik_wysokosc:
                licznik_wysokosc[i] += 1
            else:
                licznik_wysokosc[i] = 1
            if j in licznik_szerokosc:
                licznik_szerokosc[j] += 1
            else:
                licznik_szerokosc[j] = 1
licznik = 0
high = max(licznik_wysokosc.items(),key=lambda x: x[1])
width = max(licznik_szerokosc.items(),key=lambda x: x[1])

print(2*liczba_pionkow - licznik_wysokosc[high[0]] - licznik_szerokosc[width[0]])
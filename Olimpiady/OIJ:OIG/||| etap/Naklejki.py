ilosc_liter,ilosc_rang = map(int,input().split())
litery = input()
zmiany = [-1 for _ in range(ilosc_liter)]
rangi = {}
for ranga in range(ilosc_rang):
    l,p = map(int,input().split())
    l -= 1
    p -= 1
    zmiany[p] = ranga
    rangi[ranga] = p-l
print(rangi,zmiany)
akt_ranga = -1
wynik = ""
for e,litera in enumerate(litery):
    if zmiany[e] > akt_ranga:
        akt_ranga = zmiany[e]
    #print(e-rangi[akt_ranga],e)
    if akt_ranga != -1:
        wynik += wynik[e-rangi[akt_ranga]]
    else:
        wynik += litery[e]
print(wynik)
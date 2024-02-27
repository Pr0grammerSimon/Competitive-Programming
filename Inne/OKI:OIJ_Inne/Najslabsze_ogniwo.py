ilosc_liczb = int(input())
liczby = [int(i) for i in input().split()]
kolejka = []
lewe = [0 for _ in range(ilosc_liczb)]
prawe = [ilosc_liczb-1 for _ in range(ilosc_liczb)]
sumy = [0 for _ in range(ilosc_liczb+1)]
for e,i in enumerate(liczby):
    while len(kolejka) > 0:
        if kolejka[-1][0] < i:
            lewe[e] = kolejka[-1][1]+1
            break
        else:
            kolejka.pop()
    kolejka.append([i,e])
    if len(kolejka) == 1:
        lewe[e] = -1
kolejka = []
for e in range(ilosc_liczb-1,-1,-1):
    #print(kolejka)
    while len(kolejka) > 0:
        if kolejka[-1][0] < liczby[e]:
            prawe[e] = kolejka[-1][1]
            break
        else:
            kolejka.pop()
    kolejka.append([liczby[e],e])
    if len(kolejka) == 1:
        prawe[e] = -1

#print(prawe,lewe)
        
for e,liczba in enumerate(liczby):
    #if e == 0: sumy[e] = liczba
     sumy[e+1] = sumy[e]+liczba

#print(sumy)
maxi = 0
for e,liczba in enumerate(liczby):
    lewo = lewe[e] if lewe[e] != -1 else 0
    prawo = prawe[e] if prawe[e] != -1 else ilosc_liczb
    #prawo -= 1
    #print(sumy[prawo],sumy[lewo],prawo,lewo)
    maxi = max((sumy[prawo]-sumy[lewo])*liczba,maxi)
print(maxi)
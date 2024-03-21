rozmiar,ilosc_zapytan = [int(i) for i in input().split()]
kolumny = [j for j in range(1,rozmiar+1)]
wiersze = [j for j in range(1,rozmiar+1)]
for i in range(ilosc_zapytan):
    typ,a,b = input().split()
    if typ == 'W':
        wiersze[int(a)-1],wiersze[int(b)-1] = wiersze[int(b)-1],wiersze[int(a)-1]
        #print(wiersze)
    elif typ == 'K':
        kolumny[int(a)-1],kolumny[int(b)-1] = kolumny[int(b)-1],kolumny[int(a)-1]
        #print(kolumny)
    else:
        print((wiersze[int(a)-1] - 1) * rozmiar + kolumny[int(b)-1])
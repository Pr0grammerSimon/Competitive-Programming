ilosc_cyfr,reszta = input().split()
ilosc_cyfr,reszta = int(ilosc_cyfr),int(reszta)
ciag = input()
dane = {0:1%reszta}
for i in range(1,ilosc_cyfr):
    if ciag[i] == '1':
        wynik = 0
        for j in range(i-6,i):
            if j in dane:
                wynik += dane[j]
        dane[i] = wynik % reszta

print(dane[ilosc_cyfr-1])
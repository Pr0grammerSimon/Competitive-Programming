ilosc_cyfr,roznica = input().split()
ilosc_cyfr,roznica = int(ilosc_cyfr),int(roznica)
cyfry = input().split()
ilosc = {}
wynik = 0

for e,i in enumerate(cyfry):
    if i in ilosc:
        ilosc[i] += 1
    else:
        ilosc[i] = 1
    wynik += (ilosc[i] - 1)
    if e+1 > roznica:
        ilosc[cyfry[e-roznica]] -= 1
print(wynik)
#print(ilosc)
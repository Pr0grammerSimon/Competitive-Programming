ilosc_skrzyn,ilosc_kluczy = input().split()
ilosc_kluczy = int(ilosc_kluczy)
klucze = [int(i) for i in input().split()]
klucze.sort()
czas_srebrny,czas_zloty = 0,0
czas_srebrny = klucze[-1]
for i in range(int(ilosc_skrzyn)-1,-1,-1):
    #print("UWU1")
    if ilosc_kluczy > 0: 
        ilosc_kluczy -= 1
    else:
        #print("UWU")
        czas_zloty += klucze[i]
print(max(czas_zloty,czas_srebrny))
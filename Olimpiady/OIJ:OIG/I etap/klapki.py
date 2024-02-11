ilosc_osob = int(input())
wzrost = [int(i) for i in input().split()]
ilosc_klapek = int(input())
klapki = [int(i) for i in input().split()]
minimalny_wzrost = int(input())



licznik = 0


wzrost.sort()
klapki.sort()
#print(wzrost)
#print(wzrost)
for cm in wzrost:
    if cm >= minimalny_wzrost:
        licznik += 1
    elif len(klapki) > 0 and klapki[-1] + cm >= minimalny_wzrost:
        klapki.pop()
        licznik += 1
    #print(klapki,cm,licznik)

print(licznik)
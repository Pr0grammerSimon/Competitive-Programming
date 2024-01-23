ilosc_osob = 5
wzrost = [7, 3, 2, 5, 1]
ilosc_klapek = 0
klapki = []
minimalny_wzrost = 3



licznik = 0


wzrost.sort(reverse=True)
klapki.sort()

#print(wzrost)
for cm in wzrost:
    if cm >= minimalny_wzrost:
        licznik += 1
    else:
        mini = 0
        for klapek in klapki:
            if cm + klapek >= minimalny_wzrost:
                licznik += 1
                klapki.remove(klapek)
                break
        break

print(licznik)
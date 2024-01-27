ilosc_ksiazek,maksi = input().split()
ilosc_ksiazek,maksi = int(ilosc_ksiazek),int(maksi)
ksiazki = input().split()
left = 0
right = 0
akt_czas = 0
wynik = 0
while left < ilosc_ksiazek and right < ilosc_ksiazek:
    while right < ilosc_ksiazek and akt_czas <= maksi:
        akt_czas += int(ksiazki[right])
        right+=1
        if akt_czas <= maksi:
            wynik = max(wynik, right-left)
    akt_czas -= int(ksiazki[left])
    left+=1
print(wynik)


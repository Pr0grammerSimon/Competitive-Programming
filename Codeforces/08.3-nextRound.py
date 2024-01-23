liczba_osob,osoba = input().split()
osoby = input().split()
mini = int(osoby[int(osoba) -1])
#if osoby[mini]
licznik = 0
#print(mini)

for i in osoby:
    if int(i) >= mini and int(i) > 0:
        licznik += 1
print(licznik)

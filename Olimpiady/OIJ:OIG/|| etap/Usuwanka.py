import queue
ilosc_liczb = int(input())
liczby = [int(i) for i in input().split()]
idx_liczba = 0
wynik = 0
granica = 0
kolejka = queue.PriorityQueue()
while granica < ilosc_liczb:
    while idx_liczba <= granica:
        kolejka.put(-liczby[idx_liczba])
        idx_liczba+=1
    granica += abs(kolejka.get())+1
    wynik += 1
print(wynik)



'''
while idx_liczba+akt_liczba+1 < ilosc_liczb:
    print(akt_liczba)
    nowa_liczba = max(liczby[idx_liczba+1:idx_liczba+akt_liczba+2])
    print(nowa_liczba)
    print(liczby[idx_liczba+1:idx_liczba+akt_liczba+2])
    idx_liczba += (len(liczby[idx_liczba+1:idx_liczba+akt_liczba+2]) - liczby[idx_liczba+1:idx_liczba+akt_liczba+2][::-1].index(nowa_liczba))
    wynik += 1
    print(nowa_liczba,idx_liczba)
    akt_liczba = nowa_liczba
'''
"""
akt_idx = 0
while akt_idx <= ilosc_liczb:
    usun = max(liczby[idx_liczba : akt_idx+1])
print(wynik)
"""


import queue
kolejka = queue.PriorityQueue()
ilosc_leveli = int(input())
levele = [int(i) for i in input().split()]
akt_wynik = 0
ilosc_zmian = 0
for level in levele:
    #print(kolejka.queue,akt_wynik)
    if level < 0:
        kolejka.put(level)
        if abs(level) > akt_wynik:
            item = kolejka.get()
            akt_wynik += abs(item)
            akt_wynik += abs(item)
            ilosc_zmian += 1
    akt_wynik += level
#print(kolejka.queue,akt_wynik)
print(ilosc_zmian)
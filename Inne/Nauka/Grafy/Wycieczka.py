import collections
ilosc_wierzcholków,ilosc_polaczen = input().split()
ilosc_wierzcholków,ilosc_polaczen = int(ilosc_wierzcholków),int(ilosc_polaczen)
graf = {i:[] for i in range(1,ilosc_wierzcholków+1)}
for _ in range(ilosc_polaczen):
    a,b = input().split()
    graf[int(a)].append(int(b))
    graf[int(b)].append(int(a))

def bfs(punkt):
    kolejka = collections.deque([punkt])
    najkrotsza = [float('inf') for _ in range(ilosc_wierzcholków+1)]
    najkrotsza[punkt] = 0
    while len(kolejka) > 0:
        odcinek = kolejka.popleft()
        for sasiad in graf[odcinek]:
            if najkrotsza[sasiad] > (najkrotsza[odcinek] + 1):
                najkrotsza[sasiad] = (najkrotsza[odcinek] + 1)
                kolejka.append(sasiad)
    return najkrotsza

#print(bfs(1))
a,b,c = input().split()
a,b,c = int(a),int(b),int(c)
wynik_1 = bfs(a)
wynik_2 = bfs(c)
print("TAK") if (wynik_1[b] == (wynik_1[c]+wynik_2[b])) else print("NIE")

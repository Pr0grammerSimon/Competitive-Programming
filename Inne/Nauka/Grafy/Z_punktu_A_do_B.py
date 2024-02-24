liczba_miast,polaczenia = input().split()
liczba_miast,polaczenia = int(liczba_miast),int(polaczenia)
a,b = input().split()
a,b = int(a),int(b)
wyniki = ["niestety" for i in range(liczba_miast+1)]
sasiedzi = {i:[] for i in range(liczba_miast+1)}
odwiedzeni = set([a])

for i in range(polaczenia):
    p_1,p_2 = input().split()
    sasiedzi[int(p_1)].append(int(p_2))

import collections
kolejka = collections.deque([a])
wyniki[a] = 0
while len(kolejka) > 0:
    wierzcholek = kolejka.popleft()
    #print(wierzcholek)
    for sasiad in sasiedzi[wierzcholek]:
        #print(sasiad)
        if sasiad not in odwiedzeni:
            kolejka.append(sasiad)
            wyniki[sasiad] = (wyniki[wierzcholek] + 1)
            odwiedzeni.add(sasiad)

print(wyniki[b])
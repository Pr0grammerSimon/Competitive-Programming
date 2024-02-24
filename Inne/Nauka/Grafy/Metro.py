wysokosc,szerokosc = input().split()
wysokosc,szerokosc = int(wysokosc),int(szerokosc)
ilosc_stacji = int(input())
odleglosc = [[0 for _ in range(szerokosc)] for _ in range(wysokosc)]
odwiedzone = set()
d_x = [0,0,-1,1]
d_y = [-1,1,0,0]
import collections
kolejka = collections.deque()

for i in range(ilosc_stacji):
    wysokosc_,szerokosc_ = input().split()
    kolejka.append((int(wysokosc_)-1,int(szerokosc_)-1))
    odwiedzone.add((int(wysokosc_)-1,int(szerokosc_)-1))

while len(kolejka) > 0:
    punkt = kolejka.popleft()
    for i in range(4):
        if (punkt[0]+d_y[i],punkt[1]+d_x[i]) in odwiedzone: continue
        if punkt[1]+d_x[i] < szerokosc and punkt[1]+d_x[i] >= 0 and punkt[0]+d_y[i] < wysokosc and punkt[0]+d_y[i] >= 0:
            kolejka.append((punkt[0]+d_y[i],punkt[1]+d_x[i]))
            odwiedzone.add((punkt[0]+d_y[i],punkt[1]+d_x[i]))
            odleglosc[punkt[0]+d_y[i]][punkt[1]+d_x[i]] = (odleglosc[punkt[0]][punkt[1]] + 1 )

for i in odleglosc:
    for j in i:
        print(j,end=" ")
    print()
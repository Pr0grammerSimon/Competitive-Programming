import collections
ilosc_kursow,wymagania = map(int,input().split())
graf = {i:[] for i in range(1,ilosc_kursow+1)}
rodzice = {i:[] for i in range(1,ilosc_kursow+1)}
wagi = [0 for _ in range(ilosc_kursow+1)]
for _ in range(wymagania):
    a,b = map(int,input().split())
    graf[a].append(b)
    rodzice[b].append(a)
    wagi[b] += 1
stos = collections.deque()
for k,v in rodzice.items():
    if len(v) == 0: stos.append(k)

wynik = []

while stos:
    punkt = stos.popleft()
    wynik.append(str(punkt))
    for i in graf[punkt]:
        wagi[i] -= 1
        if wagi[i] == 0:
            stos.append(i)

da_sie = True
for i in wagi:
    if i != 0:
        da_sie = False
        break
if da_sie:   
    print(" ".join(wynik))
else:
    print("IMPOSSIBLE")
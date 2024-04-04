import sys
sys.setrecursionlimit(200000)
ilosc_miast,ilosc_zapytan = map(int, input().split())
x = {}
y = {}
graf = {}
for i in range(ilosc_miast):
    a,b = map(int, input().split())
    graf[i+1] = set()
    if a not in x: 
        x[a] = i+1
    else:
        graf[x[a]].add(i+1)
        graf[i+1].add(x[a])
    if b not in y:
        y[b] = i+1
    else:
        graf[y[b]].add(i+1)
        graf[i+1].add(y[b])

odwiedzone = [False for _ in range(ilosc_miast+1)]
kolory = [False for _ in range(ilosc_miast+1)]
kolor = 0
def bfs(wierzcholek):
    global odwiedzone
    kolory[wierzcholek] = kolor
    odwiedzone[wierzcholek] = True
    for sasiad in graf[wierzcholek]:
        if not odwiedzone[sasiad]: bfs(sasiad)

for i in range(1,ilosc_miast+1):
    if not odwiedzone[i]: 
        kolor = i
        bfs(i)
for _ in range(ilosc_zapytan):
    a,b = map(int,input().split())
    print("TAK") if kolory[a] == kolory[b] else print("NIE")

        
            

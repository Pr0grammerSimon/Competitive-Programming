import queue
ilosc_testow = int(input())

def sprawdz(otwarte,n):
    kolejka = queue.PriorityQueue()
    for i in range(1,n+1):
        if not otwarte[i]: continue
        akt = (float('inf'),float('inf'))
        while not kolejka.empty():
            k = kolejka.get()
            if k[0] > i:
                akt = k
                kolejka.put(k)
                break
        for j in otwarte[i]:
            if j > akt[0]:
                return [(i,j),(akt[1],akt[0])]
            kolejka.put((j,i))
    return -1

def solution():
    n = int(input())
    otwarte = [set() for _ in range(n+1)]
    for _ in range(n-2):
        a,b = map(int,input().split())
        if a > b: a,b = b,a
        otwarte[a].add(b)
    a,b = sprawdz(otwarte,n)
    otwarte[a[0]].remove(a[1])
    wynik = sprawdz(otwarte,n)
    if wynik == -1: print(a[0],a[1])
    else: print(b[0],b[1])
for _ in range(ilosc_testow):
    solution()
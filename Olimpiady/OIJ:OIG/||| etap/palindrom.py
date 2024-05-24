#O(N log N) In C++ 100% In Python 70%
N = 2**18
drzewo = [0 for _ in range(N*2+1)]

def update(val,n):
    n = n + N
    drzewo[n] = val
    n//=2
    while n > 0:
        drzewo[n] = max(drzewo[n*2],drzewo[n*2+1])
        n//=2

def query(l,p):
    l = l+N-1
    r = p+N+1
    wynik_tree = 0
    while (l//2) != (r//2):
        if l % 2 == 0: wynik_tree = max(wynik_tree, drzewo[l+1])
        if r % 2 == 1: wynik_tree = max(wynik_tree, drzewo[r-1])
        l//=2
        r//=2
    return wynik_tree
pos = [[] for _ in range(200007)]
wyniki = [0 for _ in range(int(2e5+7))]

wynik = 0
ilosc_liczb = int(input())
liczby = input().split()
for e,i in enumerate(liczby):
    for v in pos[int(i)]:
        wynik_2 = query(v+1,e)
        update(wynik_2+2,v)
        wynik = max(wynik_2+2,wynik)

    pos[int(i)].append(e)

print(wynik)
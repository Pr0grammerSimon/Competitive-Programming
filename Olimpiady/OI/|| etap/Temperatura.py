ilosc_temperatur = int(input())
temperatury = []
n = int(2**20)
drzewo = [0 for i in range(n*2)]
def query(left,right):
    l = left-1+n
    r = right+1+n
    wynik = int(-1e9+7)
    while l//2 != r//2:
        if l % 2 == 0: wynik = max(wynik,drzewo[l+1])
        if r % 2 == 1: wynik = max(wynik,drzewo[r-1])
        l//=2
        r//=2
    return wynik
def edit(poz,value):
    poz += n
    drzewo[poz] = value
    poz//=2
    while poz > 0:
        drzewo[poz] = max(drzewo[poz*2],drzewo[poz*2+1])
        poz//=2

for i in range(ilosc_temperatur):
    a,b = input().split()
    edit(i,int(a))
    temperatury.append([int(a),int(b)])

right = 0
wynik = int(-1e9+7)

for i in range(ilosc_temperatur):
    while right < ilosc_temperatur and query(i,right) <= temperatury[right][1]:
        right += 1
        wynik = max(wynik,right-i)

print(wynik)
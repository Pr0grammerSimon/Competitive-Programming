ilosc_liczb = int(input())
liczby = list(map(int,input().split()))
ilosc_zapytan = int(input())

LOG = 18
potegi = [0,0]
for i in range(2,ilosc_liczb+2):
    potegi.append(potegi[i//2]+1)

tab = [[0 for _ in range(LOG+1)] for _ in range(ilosc_liczb+2)]
for e,i in enumerate(liczby):
    tab[e][0] = i
for i in range(1,LOG+1):
    x=0
    while (x+(2**i)<=ilosc_liczb):
        tab[x][i] = min(tab[x][i-1],tab[x+(2**(i-1))][i-1])
        x+=1

for i in range(ilosc_zapytan):
    a,b = map(int,input().split())
    potega = potegi[b-a+1]
    print(min(tab[a][potega],tab[b-(2**potega) + 1][potega]))
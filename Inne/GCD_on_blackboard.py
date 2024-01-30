MAXN = int(1e5 + 7)
tab = [0 for _ in range(MAXN)]
prefNWD = [0 for _ in range(MAXN)]
sufNWD = [0 for _ in range(MAXN)]
wynik= 0

def NWD(a,b):
    while b != 0:
        tmp = b
        b = a % b
        a = tmp
    return a

n = int(input())
for e,i in enumerate(input().split()):
    tab[e+1] = int(i)

for i in range(1,n+1):
    prefNWD[i] = NWD(tab[i],prefNWD[i - 1])

for i in range(n,0,-1):
    sufNWD[i] = NWD(tab[i],sufNWD[i + 1])

for i in range(1,n+1):
    wynik = max(NWD(prefNWD[i-1],sufNWD[i+1]),wynik)
print(wynik)
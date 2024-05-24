#Python 70pkt
akt_ilosc = [0 for _ in range(200007)]
akt_ilosc[0] = 1
_,n = map(int,input().split())
for i in input().split():
    akt_ilosc[int(i)] += akt_ilosc[int(i)-1]
print(akt_ilosc[n]%int((1e9+9)))


MAXN = 10 + 7
POJEMNOSC = 1024
ileSzampana = [[0 for i in range(MAXN)] for i in range(MAXN)]

n, t = input().split()
n = int(n)
t = int(t)

wynik = 0
ileSzampana[0][0] = t * POJEMNOSC
#print(ileSzampana)
for wiersz in range(0,n):
    for kolumna in range(0,wiersz+1):
        
        if ileSzampana[wiersz][kolumna] >= POJEMNOSC:
            wynik += 1
            nadwyzka = ileSzampana[wiersz][kolumna] - POJEMNOSC
            ileSzampana[wiersz+1][kolumna] += nadwyzka // 2
            ileSzampana[wiersz+1][kolumna+1] += nadwyzka // 2

print(wynik)

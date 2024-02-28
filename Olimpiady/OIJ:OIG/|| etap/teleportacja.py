n = int(input())
akt_liczba = 1
if n % 2 == 0:
    liczba_ruchow = 2
    n-=2
else:
    liczba_ruchow = 1
    n-=1

while n > 0:
    #print(akt_liczba,n)
    if n % (akt_liczba*2) == 0:
        akt_liczba*=2
        liczba_ruchow += 1
    else:
        liczba_ruchow += 1
    n-=akt_liczba
        
print(liczba_ruchow)
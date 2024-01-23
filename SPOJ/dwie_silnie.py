i = int(input())

memo = {1:1}
def silnia(n,memo):
    if n in memo: return str(memo[n])
    maxi = max(memo)
    #print(maxi)
    wynik = memo[maxi]
    for j in range(maxi+1,n+1):
        wynik *= j
        memo[j] = wynik
        #print(memo)
    return str(wynik)

for j in range(i):
    cyfry = int(input())
    if cyfry < 10:
        wynik = silnia(cyfry,memo)
        if len(wynik) > 1:
            print(wynik[-2],wynik[-1])
        else:
            print(0,wynik[0])
    else:
        print('0 0')

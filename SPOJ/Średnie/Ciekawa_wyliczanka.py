
potegi = [2**i-1 for i in range(1,31)]

liczba = int(input())
for e,potega in enumerate(potegi):
    if liczba < potega:
        ilosc = e
        break
liczba_2 = liczba - potegi[ilosc-1]

for i in range(ilosc,0,-1):
    polowa = (2**i)//2
    j = liczba_2%2**i
    if j < polowa:
        print(5, end='')
    else:
        print(6, end='')
ilosc_ocen = int(input())
suma = 0
ilosc = 0
for i in range(ilosc_ocen):
    a,b = map(int,input().split())
    suma += a*b
    ilosc += b
if suma/ilosc >= 4.75: print("TAK")
else: print("NIE")
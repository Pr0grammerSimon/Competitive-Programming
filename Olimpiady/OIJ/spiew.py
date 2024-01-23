import math
ilosc_miejsc = input()
ciag = input().split('W')
wynik = 0
for i in ciag:
    wynik += math.ceil(len(i)/3)
print(wynik)
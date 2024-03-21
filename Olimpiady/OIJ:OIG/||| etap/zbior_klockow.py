import collections
ilosc = int(input())
liczby = sorted([int(i) for i in input().split()])
licznik = collections.Counter(liczby)
suma = 0
for i in licznik.keys():
    if suma >= i:
        if (suma-i+1) < licznik[i]:
            suma -= (suma-i+1)
            suma += licznik[i]
    else:
        suma += licznik[i]

print(suma)
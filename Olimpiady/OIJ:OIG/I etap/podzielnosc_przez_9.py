liczba = [int(i) for i in input()]
suma = sum(liczba)

reszta = suma % 9


if reszta != 0:
    if liczba[-1] > reszta:
        liczba[-1] -= reszta
    else:
        liczba[-1] += (9 - reszta)

for i in liczba: print(i,end="")
reszta = float(input())
import math

nominaly = [ 5, 2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01]
suma = 0
for i in nominaly:
    ilosc,reszta = divmod(reszta,i)
    reszta = round(reszta,2)
    #print(reszta)
    suma += ilosc

print(int(suma))

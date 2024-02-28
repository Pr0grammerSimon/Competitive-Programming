import math
i_osob,widocznosc,y,x,licznik = *[int(i) for i in input().split()],0
for osoba in range(i_osob):
    y_o,x_o = input().split()
    if math.sqrt(math.pow(int(x_o)-x,2)+math.pow(int(y_o)-y,2)) > widocznosc: licznik += 1
print(licznik)
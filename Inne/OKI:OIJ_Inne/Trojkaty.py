ciagi = input().split()
import math
try:
    mianownik_lcm = math.lcm(*[int(i.split('/')[1]) for i in ciagi])
    liczby = []
    for liczba in ciagi:
        liczebnik,mianownik = liczba.split('/')
        liczebnik,mianownik = int(liczebnik),int(mianownik)
        liczby.append(liczebnik*(mianownik_lcm//mianownik))
    liczby.sort()
    print("TAK") if (liczby[0]+liczby[1] > liczby[-1]) else print("NIE")
except:
    print("NONSENS")
import re
wejscie = input()
liczby = re.findall(r'-?\d+\.\d+|-?\d+', wejscie)
wynik = []
for liczba in liczby:
    if '.' in liczba:
        nowa_liczba = float(liczba) - 1
        znak = '+' if nowa_liczba >= 0 else '-'
        wynik.append(f"{znak}{abs(nowa_liczba):06.2f}f")
    else:
        nowa_liczba = int(liczba) + 1
        znak = '+' if nowa_liczba >= 0 else '-'
        wynik.append(f"{znak}{abs(nowa_liczba):06.2f}")
        
print('|'.join(wynik))

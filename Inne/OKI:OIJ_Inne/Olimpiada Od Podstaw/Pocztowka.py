ilosc,mini = input().split()
ilosc,mini = int(ilosc),int(mini)
wysokoscie = [int(i) for i in input().split()]
indexy = [-1]
for e,wysokosc in enumerate(wysokoscie):
    if wysokosc >= mini: indexy.append(e)
wynik = 0
for i in range(int(ilosc)-1,-1,-1):
    if indexy[-1] > i: indexy.pop()
    wynik += (i+1-(i-indexy[-1]))
print(wynik)


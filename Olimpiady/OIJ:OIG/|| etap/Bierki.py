ilosc_bierek = int(input())
lista = []
for i in range(ilosc_bierek):
    lista.append(int(input()))
lista = sorted(lista)
left = 0
right = 2
wynik = 0

while left < ilosc_bierek-2:
    if (lista[left] + lista[left+1]) > lista[right]:
        wynik = max(wynik,right - left+1)
        if right < ilosc_bierek-1:
            right += 1
        else:
            left += 1
    else:
        left+=1

print(wynik)
#Second solution
"""
while left < ilosc_bierek - 2:
    while True:
        if right == ilosc_bierek:
            right -= 1
            break
        elif lista[left] + lista[left+1] > lista[right]:
            right += 1
        else:
            right -= 1
            break
    wynik = max(wynik, right - left + 1)
    left += 1
print(wynik)
"""
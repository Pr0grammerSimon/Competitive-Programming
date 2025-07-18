ilosc_smakolykow,ilosc_rodzaji = [int(i) for i in input().split()]
ilosc = [0 for _ in range(ilosc_smakolykow+1)]
smakolyki = [int(i) for i in input().split()]
wynik = 0
right = 0
for left in range(ilosc_smakolykow):
    while ilosc[smakolyki[right]] < 1:
        ilosc[smakolyki[right]] += 1
        right += 1
        wynik += right-left
        if right == ilosc_smakolykow: break
    if right == ilosc_smakolykow: break
    ilosc[smakolyki[left]] -= 1

print(wynik)
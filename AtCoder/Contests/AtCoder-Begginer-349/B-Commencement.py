import string
strt = input()
slownik = {i:0 for i in string.ascii_lowercase}
for i in strt:
    slownik[i] += 1
ilosc = [0 for _ in range(101)]
for i in slownik.values():
    ilosc[i] += 1
good = True
for i in ilosc[1:]:
    if i != 0 and i != 2:
        good = False
        print("No")
        break
if good: print("Yes")

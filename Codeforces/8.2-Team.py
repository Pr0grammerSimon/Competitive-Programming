i = input()
ogolny = 0
for j in range(int(i)):
    osoby = input().split()
    licznik = 0
    for i in osoby:
        licznik += int(i)
    if licznik > 1:
        ogolny += 1
print(ogolny)
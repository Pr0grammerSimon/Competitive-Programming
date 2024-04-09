ilosc_nawozow,dlugosc_ogrodka = map(int, input().split())
potrzeba = [0 for _ in range(ilosc_nawozow+1)]
ilosc_innych = 0
for i in input():
    if i == "D": ilosc_innych += 1
    else: potrzeba[int(i)] += 1

suma = 0
mozna = True
for e,i in enumerate(input().split()):
    if int(i) >= potrzeba[e+1]:
        suma += (int(i)-potrzeba[e+1])
    else:
        mozna = False
        break

if mozna and ilosc_innych <= suma:
    print("TAK")
else:
    print("NIE")
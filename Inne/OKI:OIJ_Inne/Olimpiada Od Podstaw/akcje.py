ilosc_liczb = int(input())
maks_zysk = 0
mini = float('inf')
dni = input().split()
for i in dni:
    if int(i) < mini: mini = int(i)
    maks_zysk = max(int(i)-mini,maks_zysk)
print(maks_zysk)
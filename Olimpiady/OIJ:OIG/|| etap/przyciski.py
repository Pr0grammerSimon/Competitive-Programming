ilosc_przyciskow,ilosc_ruchow = [int(i) for i in input().split()]
przyciski = [0 for i in range(ilosc_przyciskow)]
maksi = 0
mini = 0
for ruch in input().split():
    ruch = int(ruch)
    if ruch > ilosc_przyciskow:
        mini = maksi
    else:
        przyciski[ruch-1] = max(mini+1,przyciski[ruch-1]+1)
        maksi = max(maksi,przyciski[ruch-1])
for przycisk in przyciski:
    if przycisk < mini: print(mini,end=" ")
    else: print(przycisk,end=" ")
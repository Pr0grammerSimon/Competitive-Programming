from collections import Counter
i = int(input())

for j in range(i):
    wyraz = input()
    ilosc = 0
    litera = wyraz[0]
    for i in wyraz:
        if i != litera:
            if ilosc < 3:
                print(litera * ilosc,end='')
            else:
                print(litera + str(ilosc),end='')
            litera = i
            ilosc = 0
        ilosc += 1
    if ilosc < 3:
        print(litera * ilosc,end='')
    else:
        print(litera + str(ilosc),end='')

    print()



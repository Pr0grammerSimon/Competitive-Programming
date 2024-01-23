i = int(input())
for j in range(i):
    wyraz = input()
    if len(wyraz) > 10:
        print(wyraz[0]+str(len(wyraz)-2)+wyraz[-1])
    else:
        print(wyraz)

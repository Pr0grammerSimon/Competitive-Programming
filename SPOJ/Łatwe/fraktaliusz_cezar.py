import string
litery = string.ascii_uppercase
N = int(input())

for i in range(N):
    wyraz = input()
    if len(wyraz) == 7:
        index = litery.index(wyraz[0])-5
        drugi_wyraz = ''
        #print(index)
        for i in wyraz:
            drugi_wyraz += litery[(litery.index(i) - index) % 26]

        if 'FRAKTAL' == drugi_wyraz: print('tak')
        else: print('nie')
    else:
        print('nie')

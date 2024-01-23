imiona = ['Dawid', 'Grzesiek', 'Maciek', 'Marcin', 'Mariusz','Rafal']


import math
N = int(input())
for i in range(N):
    n = int(input())

    #print(n % 43)
    print(imiona[math.ceil((n % 42) / 7) - 1].upper())

    #print(imiona[int((n/49) * 10) - 1])
N = int(input())

for i in range(N):
    a,b = input().split()
    a,b = int(a),int(b)
    ilosc_ruchow = 0
    while a != b:
        if a > b:
            a//=2
        else:
            b//=2
        ilosc_ruchow+=1
    print(ilosc_ruchow)



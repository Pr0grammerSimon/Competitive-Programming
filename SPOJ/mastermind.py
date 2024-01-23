aktualny = [1,1,1,1]
while True:
    print(' '.join([str(i) for i in aktualny]))
    odpowiedz = input().split()
    if odpowiedz == ['1','1','1','1']: break
    for e,j in enumerate(odpowiedz):
        if j in {'0','-1'}:
            aktualny[e] += 1

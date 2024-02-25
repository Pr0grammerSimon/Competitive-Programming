wysokosc,szerokosc = input().split()
wysokosc,szerokosc = int(wysokosc),int(szerokosc)
Poziomo = [[0 for _ in range(szerokosc+1)] for _ in range(wysokosc+1)]
Pionowo = [[0 for _ in range(szerokosc+1)] for _ in range(wysokosc+1)]
wyniki = [[10e8 for _ in range(szerokosc+1)] for _ in range(wysokosc+1)]

tablica = []
wynik = 0
for i in range(1,wysokosc+1):
    #tablica.append('0'+input())
    akt = input()
    for e,j in enumerate(akt):
        if j == '1':
            #print(i,e)
            Poziomo[i][e] = (Poziomo[i][e-1]+1)
            Pionowo[i][e] = (Pionowo[i-1][e]+1)
            wyniki[i][e] = min(wyniki[i-1][e],Poziomo[i][e])
            wynik = max(wynik,(wyniki[i][e]*Pionowo[i][e]))


#for i in wyniki:
#    print(i)
print(wynik)
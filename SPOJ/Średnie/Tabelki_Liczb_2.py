N = int(input())

for _ in range(N):
    wiersze,kolumny = input().split()
    wiersze,kolumny = int(wiersze),int(kolumny)
    lista = []
    lista2 = [[[] for j in range(int(kolumny))] for i in range(int(wiersze))]
    for i in range(int(wiersze)):
        lista.append(input().split())
    for i in range(kolumny):
        if i % 2 == 0:
            for j in range(wiersze):
                nowy_wiersz = j+1
                nowa_kolumna = i
                if nowy_wiersz > wiersze-1:
                    nowa_kolumna+=1
                    nowy_wiersz = wiersze-1
                if nowa_kolumna > kolumny-1:
                    nowa_kolumna=0
                    nowy_wiersz = 0
                #print(nowy_wiersz,nowa_kolumna)
                lista2[nowy_wiersz][nowa_kolumna] = lista[j][i]
        else:
            for j in range(wiersze-1,-1,-1):
                nowy_wiersz = j-1
                nowa_kolumna = i
                if nowy_wiersz < 0:
                    nowy_wiersz = 0
                    nowa_kolumna = i+1
                if nowa_kolumna > kolumny-1:
                    nowa_kolumna = 0
                #print(nowy_wiersz,nowa_kolumna)
                lista2[nowy_wiersz][nowa_kolumna] = lista[j][i]
    #print(lista2)
    for i in lista2:
        #print(i)
        print(' '.join(i))
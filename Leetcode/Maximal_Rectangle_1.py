def maximalRectangle(matrix: list[list[str]]) -> int:
    h = len(matrix)
    w = len(matrix[0])
    wartosci = [[0 for _ in range(w+1)] for _ in range(h)]
    wynik = 0
    for y in range(h):
        for x in range(w):
            if matrix[y][x] == '1':
                #print(y,x,wartosci)
                wartosci[y][x+1] = wartosci[y][x] + 1
                wartosc_akt = wartosci[y][x+1]
                print(y,x,wartosci)
                for z in range(y,-1,-1):
                    wartosc_akt = min(wartosc_akt,wartosci[z][x+1])
                    if wartosc_akt == 0: break
                    wynik = max(wynik,(y-z+1)*wartosc_akt)
                    print(wartosc_akt,wynik,z,(z+1)*wartosc_akt)
            else:
                wartosci[y][x+1] = 0
        #print(wartosci)
    return wynik

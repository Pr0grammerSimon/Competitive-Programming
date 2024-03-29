#In python it has only 40 points, because of time limit 0.10s
ilosc_monet,k = map(int,input().split())
indexy = {0:-1}
poprzednia = 0
wynik = 0
for e,moneta in enumerate(input()):
    poprzednia += -k if moneta == 'R' else 1
    if poprzednia not in indexy:
        indexy[poprzednia] = e
    else:
        wynik = max(wynik,e-indexy[poprzednia])
print(wynik)
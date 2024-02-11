Pola = ['a','b','c','d','e','f','g','h']

poczatek = list(input())
poczatek[1] = int(poczatek[1])
koniec = list(input())
koniec[1] = int(koniec[1])
ilosc_ruchow = 0
odpowiedzi = []
while poczatek != koniec:
    odpowiedz = []
    if poczatek[0] > koniec[0]:
        poczatek[0] = Pola[Pola.index(poczatek[0])-1]
        odpowiedz.insert(0,'W')
    elif poczatek[0] < koniec[0]:
        poczatek[0] = Pola[Pola.index(poczatek[0])+1]
        odpowiedz.insert(0,'E')
    if poczatek[1] < koniec[1]:
        odpowiedz.insert(0,'N')
        poczatek[1] = int(poczatek[1])+1
    elif poczatek[1] > koniec[1]:
        poczatek[1] = int(poczatek[1])-1
        odpowiedz.insert(0,'S')
    ilosc_ruchow +=1
    odpowiedzi.append("".join(odpowiedz))
print(ilosc_ruchow)
print(" ".join(odpowiedzi))
dwa = 0
trzy = 0
cztery = 0
wynik = 0
karty = sorted(input())
znak = karty[0]
licznik = 0
for i in karty:
    if i != znak:
        if licznik == 2: dwa += 1
        elif licznik == 3: trzy += 1
        elif licznik == 4: cztery += 1
        znak = i
        licznik = 1
    else:
        licznik += 1
if licznik == 2: dwa += 1
elif licznik == 3: trzy += 1
elif licznik == 4: cztery += 1


while (cztery > 0 and trzy > 0) or (cztery > 1) or (dwa > 0 and (trzy > 0 or cztery > 0)) or (trzy > 1):
    #print(wynik,dwa,trzy,cztery)
    if dwa > 0:
        if trzy > 0:
            if trzy > dwa:
                wynik += dwa
                trzy -= dwa
                dwa = 0
            else:
                wynik += trzy
                dwa -= trzy
                trzy = 0
        elif cztery > 0:
            if  cztery > dwa:
                wynik += dwa
                cztery -= dwa
                dwa = 0
            else:
                wynik += cztery
                dwa -= cztery
                cztery = 0
    elif trzy > 0:
        if cztery > 0:
            #print('uwu')
            cztery -= 1
            dwa += 2
        else:
            wynik += trzy // 2
            trzy %= 2
    else:
        #print('hej')
        cztery -= 1
        dwa += 2
    #print(wynik,dwa,trzy,cztery)
print(wynik)
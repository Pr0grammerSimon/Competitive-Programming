ilosc_liczb = int(input())
liczby = [int(i) for i in input().split()]
#liczby = input()
#print(ilosc_liczb)
ciagi = []
left,right = 0,0
try:
    while left < ilosc_liczb-1:
        kolejna_cyfra = liczby[left]+1 if liczby[left] != ilosc_liczb else 1
        #print(kolejna_cyfra)
        if liczby[left+1] == kolejna_cyfra: 
            left += 1
            continue
        ciag = []
        #mniejsza = False
        if liczby[left+1] < liczby[left] and liczby[left+1] == liczby[left]-1:
            nowa_cyfra = liczby[left]
            nowa_cyfra = nowa_cyfra-1 if nowa_cyfra != 1 else ilosc_liczb
            ciag.append(liczby[left])
        else:
            nowa_cyfra = liczby[left+1]
        right = left+1
        czy_dobry = True
        while liczby[right] == nowa_cyfra:
            ciag.append(liczby[right])
            right += 1
            nowa_cyfra = nowa_cyfra-1 if nowa_cyfra != 1 else ilosc_liczb
            if right == ilosc_liczb:
                if liczby[0] != nowa_cyfra:
                    czy_dobry = False
                    break
            elif liczby[right] != nowa_cyfra:
                czy_dobry = False
                break
            if right == ilosc_liczb: break
        ciagi.append(ciag)
        left = right
        #print(ciag)
except:
    pass
if (len(ciagi) > 1 or len(ciagi) == 0) and ilosc_liczb > 2: print("NIE")
else: print("TAK")


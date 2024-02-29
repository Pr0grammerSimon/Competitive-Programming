ilosc_ruchow = int(input())
max_gora = 0
min_dol = 0
max_prawo = 0
min_lewo = 0
akt_poz = [0,0]
for i in range(ilosc_ruchow):
    ilosc,ruch = input().split()
    ilosc = int(ilosc)
    x = 0
    y = 0
    for i in ruch:
        if i == "N": 
            akt_poz[0] += 1
            y+=1
            max_gora = max(akt_poz[0],max_gora)
        elif i == "S": 
            akt_poz[0] -= 1
            y-=1
            min_dol = min(akt_poz[0],min_dol)
        elif i == "W": 
            akt_poz[1] -= 1
            x-=1
            min_lewo = min(akt_poz[1],min_lewo)
        else: 
            akt_poz[1] += 1
            x+=1
            max_prawo = max(akt_poz[1],max_prawo)
    #print(max_gora,max_prawo,min_lewo,min_dol,akt_poz)
    akt_poz[0] += y*(ilosc- (2 if ilosc > 1 else 1))
    akt_poz[1] += x*(ilosc- (2 if ilosc > 1 else 1))
    max_prawo = max(akt_poz[1],max_prawo)
    min_lewo = min(akt_poz[1],min_lewo)
    min_dol = min(akt_poz[0],min_dol)
    max_gora = max(akt_poz[0],max_gora)
    if ilosc-1 > 0:
        #print("UWU")
        #print(max_gora,max_prawo,min_lewo,min_dol,akt_poz)
        for i in ruch:
            if i == "N": 
                akt_poz[0] += 1
                y+=1
                max_gora = max(akt_poz[0],max_gora)
            elif i == "S": 
                akt_poz[0] -= 1
                y-=1
                min_dol = min(akt_poz[0],min_dol)
            elif i == "W": 
                akt_poz[1] -= 1
                x-=1
                min_lewo = min(akt_poz[1],min_lewo)
            else: 
                akt_poz[1] += 1
                x+=1
                max_prawo = max(akt_poz[1],max_prawo)

    #print(max_gora,max_prawo,min_lewo,min_dol,akt_poz)

print(max_gora+abs(min_dol),max_prawo+abs(min_lewo))
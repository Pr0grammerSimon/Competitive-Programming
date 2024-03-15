ciag = input()
#print(ciag)
slownik = {}
for i in ciag:
    if i not in slownik:
        slownik[i] = 1
    else:
        slownik[i] += 1


slowo = ""
ostatnia = ""
przed_ostatnia = ""
da_sie = True
try:
    while da_sie:
        s = sorted(slownik, key= lambda x: slownik[x])
        da_sie = False
        for i in range(-1,-4,-1):
            #print(i,s,s[i])
            #print(s[i],s)
            if ostatnia != s[i] and s[i] != przed_ostatnia:
                ostatnia = przed_ostatnia
                przed_ostatnia = s[i]
                slowo += s[i]
                slownik[s[i]] -= 1
                #print("AHA")
                if slownik[s[i]] < 1: del slownik[s[i]]
                #print(slownik,s)
                da_sie = True
                break


except:
    #print(i,slownik,s)
    pass

'''
while True:
    mozna_dodac = False
    for i in s:
        if i != ostatnia and i != przed_ostatnia:
            mozna_dodac = True
            slowo += i
            slownik[i] -= 1
            if slownik[i] < 1: s.remove(i)
            przed_ostatnia = ostatnia
            ostatnia = i
            break
    if not mozna_dodac: break


if len(s)>0:
    for i in s:
        pop = ""
        ost = ""
        kol = slowo[1] if len(slowo) > 1 else ""
        akt = slowo[0]
        for e,j in enumerate(slowo):
            if i != ost and i != kol and i != pop and i != akt:
                #print("OST: "+ost,"POP: "+pop,"AKT: "+akt,"KOL: "+kol,"I: "+i,slowo,e)
                #print("COS",slowo,i,e)
                #print("COS3",slowo[:e],j,slowo[e:])
                slowo = slowo[:e] + i + slowo[e:]
                #print("COS2",slowo,j,e)
                slownik[i] -= 1
                if slownik[i] < 1: break
                ost = slowo[e-1] if e-1 > -1 else ""
                pop = slowo[e]
                if e+1 < len(slowo): akt = slowo[e+1]
                else: akt=""

                if e+2 < len(slowo): kol = slowo[e+2]
                else: kol=""

'''
#print(s_1[:1]+"U"+s_1[2:])
print(slowo)
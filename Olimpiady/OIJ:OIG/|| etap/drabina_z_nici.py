def czy_dobre(igly,nicie) -> bool:
    if igly % 2 == 1: return False
    n=igly//2
    if 2*(n-1)+n-2 == nicie:
        return True
    return False
def skrajne_igly(polaczenia):
    skrajne = []
    for k,v in polaczenia.items():
        if len(v) == 1:
            skrajne.append(k)
        elif len(v) == 3:
            pass
        else:
            return {},False,0,0
    if len(skrajne) != 4: return {},False,0,0

    skrajna_1 = skrajne[0]
    pol_1 = list(polaczenia[skrajna_1])
    for i in polaczenia[pol_1[0]]:
        if i == skrajna_1: continue
        if len(polaczenia[i]) < 3: continue
        for j in polaczenia[i]:
            if j in skrajne:
                skrajna_2 = j
                break
    return skrajne,True,skrajna_1,skrajna_2



igly,nicie = input().split()
igly,nicie = int(igly),int(nicie)
slownik = {}
for i in range(nicie):
    k1,k2 = input().split()
    if k1 in slownik:
        slownik[k1].add(k2)
        #print("UWU2",slownik[k1])
    else:
        slownik[k1] = set([k2])
    if k2 in slownik:
        slownik[k2].add(k1)
    else:
        slownik[k2] = set([k1])
        #print("UWU2",slownik[k2])
def sprawdzenie_3(lewo,prawo):  
    stare_lewo = lewo
    stare_prawo = prawo  
    for _ in range(igly//2):
        nowe_lewo = lewo
        for i in slownik[lewo]:
            if i != prawo and i != stare_lewo:
                stare_lewo = lewo
                lewo = i
                break
        for i in slownik[prawo]:
            if i == lewo:return False
            elif i != nowe_lewo and i != stare_prawo:
                stare_prawo = prawo
                prawo = i
                break
    return True

skrajne,mozna,lewo,prawo=skrajne_igly(slownik)
stare_lewo = lewo
stare_prawo = prawo

if mozna and czy_dobre(igly,nicie) and sprawdzenie_3(lewo,prawo):
    print("TAK")
    for _ in range(igly//2):
        print(lewo,prawo)
        nowe_lewo = lewo
        for i in slownik[lewo]:
            if i != prawo and i != stare_lewo:
                stare_lewo = lewo
                lewo = i
                break
        for i in slownik[prawo]:
            if i == lewo:print("NIE")
            elif i != nowe_lewo and i != stare_prawo:
                stare_prawo = prawo
                prawo = i
                break
        #print(slownik)
else:
    print("NIE")

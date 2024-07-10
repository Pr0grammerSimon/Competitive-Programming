import sys
sys.setrecursionlimit(200000)

ilosc_plikow = 10
for plik in range(1,ilosc_plikow+1):
    wejscie = open(f"Inne/ONTAK 23/Junior/Only Output - Interactive/Drzewo-i-nawaiasy/Wejscie/drn{plik}.in")
    wyjscie = open(f"Inne/ONTAK 23/Junior/Only Output - Interactive/Drzewo-i-nawaiasy/Wyjscie/drn{plik}.out","w")
    ilosc_testow = int(wejscie.readline())

    for q in range(ilosc_testow):

        ilosc_wierzcholkow = int(wejscie.readline())
        ilosc_krawedzi = ilosc_wierzcholkow-1

        graf = [[] for _ in range(ilosc_wierzcholkow)]


        for i in range(ilosc_krawedzi):
            a,b = map(int,wejscie.readline().split())
            a-=1
            b-=1
            graf[a].append(b)
            graf[b].append(a)


        wyniki = ['.' for _ in range(ilosc_wierzcholkow)]

        def dfs(rodzic,v,napis):
            wyniki[v] = napis
            for i in graf[v]:
                if (i!=rodzic):
                    dfs(v,i,"(" if napis==")" else ")")

        dfs(0,0,"(")

        wyjscie.write("".join(wyniki)+"\n")
        
    wejscie.close()
    wyjscie.close()
from string import ascii_uppercase
litery = ascii_uppercase
ciagi = input().split()
secik = set()
def generuj(l_1,l_2,c_1,c_2):
    global secik
    for i in range(c_1,c_2+1):
        akt_litera = l_1
        if len(l_1) == 1:
            idx_litera = litery.index(l_1)
        else:
            idx_litera = (litery.index(l_1[0])+1)*26+litery.index(l_1[1])
        secik.add(akt_litera+str(i))
        while akt_litera != l_2:
            if idx_litera > 25:
                akt_litera = litery[idx_litera // 26 -1] + litery[idx_litera % 26]
            else:
                akt_litera = litery[idx_litera]
            idx_litera += 1
            secik.add(akt_litera+str(i))
for i in ciagi:
    ciag_1 = ""
    ciag_2 = ""
    liczba_1 = ""
    liczba_2 = ""
    znaki = i.split(":")
    for znak in znaki[0]:
        if znak in litery:
            ciag_1 += znak
        else:
            liczba_1 += znak
    for znak in znaki[1]:
        if znak in litery:
            ciag_2 += znak
        else:
            liczba_2 += znak
    #print(liczba_1,ciag_1)
    generuj(ciag_1,ciag_2,int(liczba_1),int(liczba_2))

print(len(secik))

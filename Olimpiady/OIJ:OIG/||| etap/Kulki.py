zle_1 = []
zle_2 = []

ilosc_kulek = int(input())
kulki_1 = input()
kulki_2 = input()
ilosc = kulki_1.count('B')
if ilosc > (ilosc_kulek-ilosc):
    glowne = "B"
else:
    glowne = "C"

for e,letter in enumerate(kulki_1):
    if letter != glowne:
        zle_1.append(e)
for e,letter in enumerate(kulki_2):
    if letter == glowne:
        zle_2.append(e)
#print(zle_1,zle_2)
wynik = 0
for i in range(len(zle_2)-1,-1,-1):
    wynik += abs(zle_1[i]-zle_2[i])+1
print(wynik)
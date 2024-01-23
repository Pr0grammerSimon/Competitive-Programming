
czasy = {}
czasy2 = []
wczytane = open('marathon.in','r')
n = int(wczytane.readline())
wynik = 0
for i in range(n):
    czasy2.append(wczytane.readline().split())
    if i != 0:
        czasy[i-1] = abs(int(czasy2[i-1][0])-int(czasy2[i][0])) + abs(int(czasy2[i-1][1])-int(czasy2[i][1]))
        wynik += czasy[i-1]
wczytane.close()
staly_wynik = wynik
for i in range(n):
    if i != 0 and i != n-1:
        wynik2 = abs(int(czasy2[i-1][0])-int(czasy2[i+1][0])) + abs(int(czasy2[i-1][1])-int(czasy2[i+1][1]))
        wynik = min(wynik,staly_wynik+wynik2-czasy[i]-czasy[i-1])

zapis = open('marathon.out','w')
zapis.write(str(wynik))
zapis.write('\n')
zapis.close()
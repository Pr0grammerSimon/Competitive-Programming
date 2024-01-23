plik = open('bcount.in','r')
ilosc_krow,ilosc_testow = plik.readline().split()

krowy_1 = [0]
krowy_2 = [0]
krowy_3 = [0]
for i in range(int(ilosc_krow)):
    j = int(plik.readline())
    krowy_1.append(krowy_1[i])
    krowy_2.append(krowy_2[i])
    krowy_3.append(krowy_3[i])
    if j == 1: krowy_1[i+1] += 1
    if j == 2: krowy_2[i+1] += 1
    if j == 3: krowy_3[i+1] += 1


#print(krowy_1,krowy_2,krowy_3)
wynik = open('bcount.out','w')
for i in range(int(ilosc_testow)):
    test = plik.readline().split()
    wynik.write(f"{krowy_1[int(test[1])] - krowy_1[int(test[0])-1]} {krowy_2[int(test[1])] - krowy_2[int(test[0])-1]} {krowy_3[int(test[1])] - krowy_3[int(test[0])-1]}\n")
wynik.close()
plik.close()
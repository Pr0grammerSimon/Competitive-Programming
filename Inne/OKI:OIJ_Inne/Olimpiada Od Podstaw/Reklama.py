maksi = 0
ilosc_ekranow,ilosc_kupcow,budzet = input().split()
ilosc_ekranow,ilosc_kupcow,budzet = int(ilosc_ekranow),int(ilosc_kupcow),int(budzet)
ekrany = input().split()
wejscie = input().split()
dictionary = {str(i+1):int(wejscie[i])for i in range(ilosc_kupcow)}
#print(dictionary)
left = 0
right = 0
akt = 0
dict_2 = {str(i):0 for i in range(1,ilosc_kupcow+1)}
wynik = 0
while left < ilosc_ekranow:
    #print(right)
    if dict_2[ekrany[right]] < 1:
        akt += dictionary[ekrany[right]]
        #wynik += 1
    dict_2[ekrany[right]] += 1
    #print("UWU")
    wynik+=1
    #print(wynik,akt)
    while akt > budzet:
        dict_2[ekrany[left]] -= 1
        if dict_2[ekrany[left]] < 1: 
            akt -= dictionary[ekrany[left]]
        wynik -= 1
        left += 1
    #print(akt,wynik)
    maksi = max(maksi,wynik)
    if left > right: right = left-1
    right += 1
    if right == ilosc_ekranow:
        left += 1
        right -= 1
        wynik -= 1

print(maksi)
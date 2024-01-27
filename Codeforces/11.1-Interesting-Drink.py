number_of_shops = int(input())
prices_of_bootles = input().split()
number_of_days = int(input())
#print(prices_of_bootles)
prices_of_bootles = sorted(prices_of_bootles,key=lambda x: int(x))
prefix = {0:0}
poprzedni = [0,0]
for i in range(1,number_of_shops+1):
    nowy = [int(prices_of_bootles[i-1]),poprzedni[1] + 1]
    prefix[nowy[0]] = nowy[1]
    poprzedni = nowy
    #prefix[int(i)] = prefix[int(prices_of_bootles[e-1])] + int(i)
#print(prefix)
lista_prefix = list(prefix.keys())
for i in range(number_of_days):
    wynik = 0
    amount = int(input())
    left = 0
    right = len(lista_prefix)-1
    while left <= right:
        srodek = (left+right) // 2
        #print(srodek)
        if lista_prefix[srodek] <= amount: 
            wynik = lista_prefix[srodek]
            left = srodek+1
        elif lista_prefix[srodek] > amount:
            right = srodek-1
    print(prefix[wynik])
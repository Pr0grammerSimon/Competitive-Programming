ilosc_produktow = int(input())
produkty = {}
for _ in range(ilosc_produktow):
    wejscie = input().split()
    if int(wejscie[0]) not in produkty:
        produkty[int(wejscie[0])] = int(wejscie[1])
    else: 
        produkty[int(wejscie[0])] += int(wejscie[1])
print(len(produkty))
for k,v in produkty.items():
    print(k,v)
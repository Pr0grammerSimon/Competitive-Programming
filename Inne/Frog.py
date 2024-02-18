ilosc_kamieni = int(input())
kamienie = [int(i) for i in input().split()]
wyniki = [0,abs(kamienie[1]-kamienie[0])]
for i in range(2,ilosc_kamieni):
    wyniki.append(min(wyniki[i-1]+abs(kamienie[i]-kamienie[i-1]),wyniki[i-2]+abs(kamienie[i-2]-kamienie[i])))
print(wyniki[-1])
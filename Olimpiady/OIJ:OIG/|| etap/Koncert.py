import string
slownik = {chr(i+97):i for i in range(26)}
#print(slownik)
ilosc_liter = int(input())
litery = input()
for e,i in enumerate(litery):
    if e == ilosc_liter-1:
        litery = litery[:-1]
        break
    elif slownik[litery[e+1]] < slownik[i]:
        litery = litery[:e]+litery[e+1:]
        break
print(litery)
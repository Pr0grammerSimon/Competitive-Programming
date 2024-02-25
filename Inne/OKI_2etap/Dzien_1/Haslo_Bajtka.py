import string
letters = string.ascii_lowercase
ilosc = [int(i) for i in input().split()]
suma = sum(ilosc)
wynik = 0
srodek = ""
ciag = ""
for e,i in enumerate(ilosc):
    if i > 1:
        wynik += (suma - 1)
        suma -= 2
        i -= 2
        ciag += letters[e]
    srodek += (letters[e]*i)
    
print(wynik)
print(ciag+srodek+ciag)
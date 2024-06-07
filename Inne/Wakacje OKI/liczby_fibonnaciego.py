ilosc_liczb = int(input())
akt_liczba = 1
pop_liczba = 1
print("0 1 1",end=" ")
for i in range(3,ilosc_liczb):
    print(akt_liczba+pop_liczba,end=" ")
    pop_liczba,akt_liczba = akt_liczba,pop_liczba+akt_liczba
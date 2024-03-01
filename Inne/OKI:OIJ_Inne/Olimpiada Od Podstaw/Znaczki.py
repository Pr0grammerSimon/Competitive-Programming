a,b = input().split()
ciag_1 = set(input().split())
ciag_2 = input().split()
licznik = 0
for i in ciag_2: 
    if i not in ciag_1: licznik += 1
print(licznik)
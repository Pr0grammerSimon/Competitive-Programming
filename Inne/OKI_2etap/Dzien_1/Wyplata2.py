ciag = input().strip()

left = 0
right = 0
akt = 0
wynik = 0
while left < len(ciag) and right < len(ciag):
    if ciag[left] != ciag[right]:
        akt = 0
        left = right
    akt += 1
    wynik += akt
    right += 1
print(wynik)

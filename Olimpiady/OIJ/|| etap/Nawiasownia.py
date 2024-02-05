liczba = int(input())
nawiasy = ''
while liczba > 0:
    i = 1
    while i <= liczba:
        liczba -= i
        i += 1
        nawiasy += '()'
    nawiasy += ')'
print(nawiasy)
n = int(input())
liczby = [int(i) for i in input().split()]
licznik = {}
maxi = 0
for i in liczby:
    if i not in licznik: licznik[i] = 1
    else: licznik[i] += 1
    maxi = max(maxi,i)
liczby_lista = list(licznik.keys())
liczby_lista.sort(reverse=True)
#print(liczby_lista)
secik = set()
for i in liczby_lista:
    #secik.add(i)
    if licznik[i] > 2: 
        secik.add(i)
        secik.add(i+1)
        secik.add(i-1)
    elif licznik[i] > 1:
        if i+1 not in secik:
            secik.add(i+1)
            if i not in secik:
                secik.add(i)
            else:
                secik.add(i-1)
        else:
            secik.add(i)
            secik.add(i-1)
    else:
        if i+1 not in secik:
            secik.add(i+1)
        elif i not in secik:
            secik.add(i)
        else:
            secik.add(i-1)

print(len(secik))
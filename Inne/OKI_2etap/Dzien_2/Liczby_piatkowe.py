i=1
lista_poteg = []
while i < 126:
    lista_poteg.append(i)
    i*=5

#print(lista_poteg)
def tablica(liczba,secik,liczby):
    secik.add(liczba)
    print(liczba)
    if len(liczby) == 0:
        return
    for i in liczby:
        liczby2 = set(liczby)
        liczby2.remove(i)
        if liczba+i not in secik:
            tablica(liczba+i,secik,liczby2)
    return secik
#print(lista_poteg)
lista = sorted(tablica(0,set(),lista_poteg))
#print(lista)

liczba_przedmiotow,pojemnosc = input().split()
pojemnosc,liczba_przedmiotow = int(pojemnosc),int(liczba_przedmiotow)
profit = [0]
weight = [0]
for _ in range(liczba_przedmiotow):
    j = (input().split())
    weight.append(int(j[0]))
    profit.append(int(j[1]))


tablica = [[0 for _ in range(pojemnosc+1)]for _ in range(liczba_przedmiotow+1)]
for k in range(1,liczba_przedmiotow+1):
    for c in range(1,pojemnosc+1):
        if weight[k] <= c:
            tablica[k][c] = max(profit[k] 
                              + tablica[k-1][c-weight[k]], 
                              tablica[k-1][c]) 
        else:
            tablica[k][c] = tablica[k-1][c]
print(tablica[-1][-1])


def solution(table):
    hash = {}
    wynik = 0
    for e,i in enumerate(table):
        if i-e not in hash:
            hash[i-e] = 1
        else:
            wynik += hash[i-e]
            hash[i-e] += 1
    return wynik

ilosc_testow = int(input())
for _ in range(ilosc_testow):
    _ = input()
    print(solution(map(int,input().split())))
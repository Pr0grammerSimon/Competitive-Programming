ilosc = int(input())
choregwie = input().split()
choregwie.sort(key=lambda x: (sum([int(i) for i in x]),int(x)),reverse=True)
print(' '.join(choregwie))
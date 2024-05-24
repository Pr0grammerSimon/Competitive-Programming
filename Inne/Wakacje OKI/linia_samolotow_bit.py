lista = []
for _ in range(int(input())):
    lista.append(list(input().split()))

lista.sort(key=lambda x: x[3], reverse=True)
lista.sort(key=lambda x: x[2])
lista.sort(key=lambda x: int(x[1]))
lista.sort(key=lambda x: x[0], reverse=True)
for i in lista: print(' '.join(i))
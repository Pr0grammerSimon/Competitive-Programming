lista = {}
_ = int(input())
for e,i in enumerate(input().split()):
    if i in lista:
        lista[i].append(e)
    else:
        lista[i] = [e]

wynik = float('inf')
for k,v in lista.items():
    for i in range(len(v)-2):
        wynik = min((v[i+2]-v[i] + 1),wynik)
if wynik == float('inf'):  
    print('NIE')
else:
    print(wynik)
lista = []
da_sie = False
def check():
    if lista[0][0] == lista[1][1] == lista[2][2] == "X": return True
    if lista[0][2] == lista[1][1] == lista[2][0] == "X": return True
    for i in range(3):
        git = True
        for j in range(3):
            if lista[i][j] != "X": git=False
        if git: return True
    for i in range(3):
        git = True
        for j in range(3):
            if lista[j][i] != "X": git=False
        if git: return True
for i in range(3):
    lista.append(input().split())
for i in range(3):
    for j in range(3):
        if lista[i][j] == "P": 
            lista[i][j]="X"
            if check(): da_sie = True
            lista[i][j]="P"
        elif check(): da_sie = True

if da_sie: print("TAK")
else: print("NIE")
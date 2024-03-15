nawiasy = input()
otwarte = 0
drugi = 0
odpowiedz = []
for i in nawiasy:
    if i == ")":
        otwarte += 1
        odpowiedz.append('1 3')
    elif otwarte > 0:
        otwarte -= 1
        odpowiedz.append('1 3')
    else:
        drugi += 1
        odpowiedz.append('1 2')
if otwarte == drugi:
    print(len(odpowiedz)+otwarte)
    for i in odpowiedz: print(i)
    for _ in range(otwarte): print('2 3')
else:
    print("NIE")
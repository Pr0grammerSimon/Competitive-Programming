litery = input()
praw_napis = input()
def rekurencja(pozycja,napis):
    if litery[pozycja] == napis[0]:
        napis = napis[1:]
    else: 
        return False
    
    if napis == "": return True
    if (pozycja-1) % 10 != 0:
        if rekurencja(pozycja-1,napis): return True
    if (pozycja+1) % 10 != 0:
        if rekurencja(pozycja+1,napis): return True
    if pozycja > 9:
        if rekurencja(pozycja-10,napis): return True
    if pozycja < 90:
        if rekurencja(pozycja+10,napis): return True
    
    return False

poz = -2
for e,i in enumerate(litery):
    if i == praw_napis[0]:
        wynik = rekurencja(e,praw_napis)
        if wynik: 
            poz = e
            break

print(poz+1)


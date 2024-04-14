import queue,math
kolejka  = queue.PriorityQueue()
ilosc_domow,zwiekszanie = map(int,input().split())
def odleglosc(y,x):
    return math.sqrt(math.pow(y,2)+math.pow(x,2))

def koszt(h):
    return (h-1)*h//2

for i in range(ilosc_domow):
    dane = input().split()
    maxi = 0
    for k in range(2,int(dane[0])*2+1,2):
        maxi = max(maxi,odleglosc(int(dane[k+1]),int(dane[k])))
    kolejka.put((maxi,int(dane[1])))
wynik = 0
zysk = 0
for i in range(kolejka.qsize()):
    punkt = kolejka.get()
    zysk += punkt[1]
    print(wynik,punkt[0],punkt[1])
    wysokosc = math.ceil(punkt[0]/zwiekszanie)
    wynik = max(wynik,zysk-koszt(wysokosc))

print(wynik)


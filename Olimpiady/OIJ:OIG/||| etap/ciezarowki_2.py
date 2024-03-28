#67 points in python :(
import queue
import sys
sys.setrecursionlimit(200001)
liczba_miast,liczba_drog = [int(i) for i in input().split()]
graf = {i:[] for i in range(1,liczba_miast+1)}
kolejka = queue.PriorityQueue()
zbior = [[i,0,0] for i in range(liczba_miast+2)]

for _ in range(liczba_drog):
    a,b,koszt = [int(i) for i in input().split()]
    graf[a].append([b,koszt])
    graf[b].append([a,koszt])
    kolejka.put((koszt,a,b))
ilosc_ciezarowek = int(input())
for i in input().split():
    zbior[int(i)][1] = 1
for i in input().split():
    zbior[int(i)][2] = 1

def find(v):
    if v != zbior[v][0]:
        zbior[v][0] = find(zbior[v][0])
    return zbior[v][0]

def join(v1,v2):
    global zbior
    f_1 = find(v1)
    f_2 = find(v2)
    zbior[f_1][0] = f_2
    zbior[f_2][1] += zbior[f_1][1]
    zbior[f_2][2] += zbior[f_1][2]
    ilosc = min(zbior[f_2][1],zbior[f_2][2])
    zbior[f_2][1] -= ilosc
    zbior[f_2][2] -= ilosc
    zbior[f_1][1] -= ilosc
    zbior[f_1][2] -= ilosc
    return ilosc
wynik = 0
while not kolejka.empty():
    droga = kolejka.get()
    if find(droga[1]) != find(droga[2]):
        ilosc = join(droga[1],droga[2])
        wynik += ilosc*droga[0]
print(wynik)

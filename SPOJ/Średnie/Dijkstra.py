'''
graph = {
    'A' : {'B': 2, 'D': 4},
    'B' : {'C': 3, 'D': 3},
    'C' : {'E': 2},
    'D' : {'C': 3, 'E': 4},
    'E' : {}
}
'''
def dijkstra(graph,a):
    #print(graph)
    najkrotsze = {
        i : {'pop':'NIE','cena':float('inf')} for i in graph.keys()
    }
    najkrotsze[a]['cena'] = 0
    import queue
    kolejka = queue.PriorityQueue()
    kolejka.put(a)
    while kolejka.qsize() > 0:
        wierzcholek = kolejka.get()
        #print(wierzcholek)
        for k,v in graph[wierzcholek].items():
            #print(najkrotsze[wierzcholek])
            if (najkrotsze[wierzcholek]['cena'] + v) < najkrotsze[k]['cena']:
                kolejka.put(k)
                #print(najkrotsze[wierzcholek]['cena']+v,v)
                najkrotsze[k]['cena'] = (najkrotsze[wierzcholek]['cena'] + v)
                najkrotsze[k]['pop'] = wierzcholek
    #print(najkrotsze)
    return najkrotsze




N = int(input())
for _ in range(N):
    il_wierzcholkow,il_krawedzi = input().split()
    graf = {i:{} for i in range(1,int(il_wierzcholkow)+1)}
    for i in range(1,int(il_krawedzi)+1):
        a,b,ile = input().split()
        graf[int(a)][int(b)] = int(ile)
    a,b = input().split()
    wynik = dijkstra(graf,int(a))
    if wynik[int(b)]['cena'] == float('inf'):
        print('NIE')
    else:
        print(wynik[int(b)]['cena'])
#print(najkrotsze)
n,q = map(int,input().split())
n+=1
LOG = 20
graf = [[] for _ in range(n)]
glebokosc = [0 for _ in range(n)]
poprzednik = [[1 for _ in range(LOG)] for _ in range(n)]

for _ in range(n-2):
    a,b = map(int,input().split())
    graf[a].append(b)
    graf[b].append(a)

def wyrownaj(a,roznica):
    for i in range(LOG-1,-1,-1):
        if 1<<i <= roznica:
            #print("AHA:",roznica,1<<i,a,poprzednik[a])
            roznica -= 1<<i
            a = poprzednik[a][i]
    return a

def lca(a,b):
    if glebokosc[a] < glebokosc[b]: a,b = b,a
    a = wyrownaj(a,glebokosc[a]-glebokosc[b])
    #print("PO:",a,b)
    if a == b: return a
    for i in range(LOG-1,-1,-1):
        if poprzednik[a][i] != poprzednik[b][i]:
            a = poprzednik[a][i]
            b = poprzednik[b][i]
    return poprzednik[a][0]

def dfs(v,pop):
    for i in graf[v]:
        if i != pop:
            glebokosc[i] = glebokosc[v] + 1
            poprzednik[i][0] = v
            dfs(i,v)

dfs(1,1)
for p in range(1,LOG):
    for i in range(n):
        poprzednik[i][p] = poprzednik[poprzednik[i][p-1]][p-1]
    
#print(graf,glebokosc)
for _ in range(q):
    a,b = map(int,input().split())
    #print(glebokosc[a],glebokosc[b],lca(a,b))
    print(glebokosc[a]+glebokosc[b]- 2*glebokosc[lca(a,b)])
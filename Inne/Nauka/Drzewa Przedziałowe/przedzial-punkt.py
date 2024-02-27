base = int(2**17)
tree = [1 for _ in range(2*base+1)]
mod = 10**9+7
def add(a,b,x):
    a = a-1+base
    b = b+1+base
    while a//2 != b//2:
        if  a % 2 == 0: tree[a+1] *= x
        if b % 2 == 1: tree[b-1] *= x
        a//=2
        b//=2



def query(v):
    res = 1
    v += base
    while v>0:
        res = (res * (tree[v] % mod))% mod
        v//=2
    return res


zap = int(input())
for _ in range(zap):
    wejscie = input().split()
    if wejscie[0] == '0':
        add(int(wejscie[1]),int(wejscie[2]),int(wejscie[3]))
    else:
        print(query(int(wejscie[1])))


base = int(2**17)
tree = [0 for i in range(2*base+1)]

def add(v, x):
    v = v+base
    tree[v] = x
    v//=2
    while v > 0:
        tree[v] = max(tree[2*v],tree[2*v+1])
        v //= 2

def query(a ,b ):
    res = 0
    a = a-1+base
    b = b+1+base
    while (a//2)!=(b//2):
        if a % 2 == 0: res = max(res,tree[a+1])
        if b % 2 == 1: res = max(res, tree[b-1])
        a//=2
        b//=2
    return res

ilosc_zapytan = int(input())
for _ in range(ilosc_zapytan):
    d,a,b = input().split()
    if d == '0':
        add(int(a),int(b))
    else:
        print(query(int(a),int(b)))
T = int(input())


def nwd(n, k):
    x = 0
    while k != 0:
        x = n % k
        n, k = k , x
    return n

def nww(n, k):
    return n*k // nwd(n, k)

for i in range(T):
    cyfry = input().split()
    print(nww(int(cyfry[0]),int(cyfry[1])))
ilosc_punktow = int(input())
punkty = [int(i) for i in input().split()]
punkty.sort(reverse=True)
sumy = [punkty[0]]
for i in range(1,ilosc_punktow):
    sumy.append(sumy[i-1]+punkty[i])

def binary_search(n):
    left = 0
    right = ilosc_punktow-1
    while left<=right:
        srodek = (left+right)//2
        #print(srodek,punkty[srodek])
        if sumy[srodek] < n:
            left = srodek+1
        #elif sumy[srodek] < n:
            #left = srodek+1
        else:
            right = srodek-1
        
    print(left+1)

N = int(input())
for _ in range(N):
    binary_search(int(input()))
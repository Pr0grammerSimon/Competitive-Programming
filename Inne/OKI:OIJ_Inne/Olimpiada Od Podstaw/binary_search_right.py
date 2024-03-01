ilosc_cyfr,_ = input().split()
ilosc_cyfr = int(ilosc_cyfr)
cyfry = [int(i) for i in input().split()]
def binary_search_right(n):
    left = 0
    right = ilosc_cyfr - 1
    while left < right:
        mid = (right+left) // 2
        if cyfry[mid] >= n:
            right = mid
        else:
            left = mid+1
    print(right+1)

for i in input().split(): 
    if int(i)<=cyfry[-1]:binary_search_right(int(i))
    else: print("F")
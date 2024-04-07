import math
_ = int(input())
budynki = [int(i) for i in input().split()]

def da_sie(h):
    progress = 0
    for e,budynek in enumerate(budynki):
        if progress == h:
            if budynek >= (h*2+1):
                progress += 1
            elif budynek < (h+1):
                progress = 0
        elif budynek >= (h+1):
                progress += 1
        else:
                progress = 0
        if progress == (h*2+1): return True
    return False
    
    
left = 0
right = 200000
while left < right:
    mid = math.ceil((left+right) / 2)
    if da_sie(mid): left=mid
    else: right = mid-1
    
print(left)
liczby,wykresl = input().split()
liczby,wykresl = int(liczby),int(wykresl)
secik = set([i for i in range(1,int(liczby)+1)])
from collections import deque

kolejka = deque([i for i in range(liczby-wykresl+1,liczby+1)])
while len(kolejka) > 0:
    element = kolejka.popleft()
    for i in secik.copy():
        if i <= element:
            if element % i == 0: secik.remove(i)

try:        
    print(min(secik))
except:
    print('-1')
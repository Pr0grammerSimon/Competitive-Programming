N = int(input())
wyniki = {-3:0,-2:0,-1:0,0:0}
pop = 0
wyniki[1] = int(input())
if 2<= N:
    pop = int(input())
    wyniki[2] = pop+wyniki[1]
for i in range(3,N+1):
    filar = int(input())
    wyniki[i] = max(wyniki[i-1],wyniki[i-2]+filar,wyniki[i-3]+pop+filar)
    #print(wyniki[i],filar,wyniki[i-3],pop)
    pop = filar
print(wyniki[N])
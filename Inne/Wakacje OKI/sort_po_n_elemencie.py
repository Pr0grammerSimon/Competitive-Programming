N = int(input())
dict_ = {}
for i in range(N):
    a,b,c = map(int,input().split())
    dict_[tuple([a,b,c])] = i+1

a,b,c = map(int,input().split())
lista = sorted(dict_.keys(),key=lambda x: (x[a-1],x[b-1],x[c-1]),reverse=True)

for i in lista: print(dict_[i],end=" ")
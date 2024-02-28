Liczba_desek = int(input())
deski = sorted([int(i) for i in input().split()])
print(deski[-4]*deski[-4]) if len(deski)>3 else print(0)
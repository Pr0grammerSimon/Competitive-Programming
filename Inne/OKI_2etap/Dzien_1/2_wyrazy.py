w,p = input().split()
wyrazy = input().split()
i=0
while i+1 < int(w) and i//2 < int(p):
    print(wyrazy[i],wyrazy[i+1])
    i+=2
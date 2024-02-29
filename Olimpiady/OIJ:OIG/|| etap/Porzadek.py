ilosc_liter = int(input())
litery = input()
ilosc_r = [0]
ilosc_n = [0]
sumy = [0]
for i in range(ilosc_liter):
    ilosc_r.append(ilosc_r[i])
    ilosc_n.append(ilosc_n[i])
    sumy.append(sumy[i])
    if litery[i] == 'N': 
        ilosc_n[i+1] += 1
        #print(ilosc_r[i])
        sumy[i+1] += ilosc_r[i]
    else: ilosc_r[i+1] += 1

#print(sumy,ilosc_n,ilosc_r)
N = int(input())
for _ in range(N):
    a,b = input().split()
    a,b = int(a),int(b)
    print(sumy[b]-sumy[a-1]-(ilosc_n[b]-ilosc_n[a-1])*ilosc_r[a-1])
ilosc_osob,ilosc_zapytan = input().strip().split()
print(ilosc_osob)
ilosc_osob,ilosc_zapytan = int(ilosc_osob),int(ilosc_zapytan)
osoby = input().strip().split()
lewa = {0:0}
ilosc_jedynek = {0:0}
ilosc_zer = {0:0}
#print("UWU")
for e,i in enumerate(osoby):
    if i == "0": 
        lewa[e+1] = lewa[e]
        ilosc_zer[e+1] = ilosc_zer[e] + 1
        ilosc_jedynek[e+1] = ilosc_jedynek[e]
    else: 
        lewa[e+1] = lewa[e]+ilosc_zer[e]
        ilosc_zer[e+1] = ilosc_zer[e]
        ilosc_jedynek[e+1] = ilosc_jedynek[e] + 1
        
       #ilosc_jedynek += 1
#print("UWU2")
#print(lewa,ilosc_jedynek,ilosc_zer)
for _ in range(ilosc_zapytan):
    a,b = input().split()
    a,b = int(a),int(b)
    if (lewa[b]-lewa[a-1]-((ilosc_jedynek[b]-ilosc_jedynek[a-1])*ilosc_zer[a-1])) < 0:
        print("0")
    else:
        print(lewa[b]-lewa[a-1]-((ilosc_jedynek[b]-ilosc_jedynek[a-1])*ilosc_zer[a-1]))
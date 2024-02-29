ilosc_wagonow = int(input())
wagony = input().split()
miasta = [int(i) for i in input().split()]
wagony = [int(i) for i in wagony][::-1]
hash = {miasta[0]:ilosc_wagonow}
akt = ilosc_wagonow
okrazenia = 0
for i in range(1,ilosc_wagonow):
    hash[miasta[i]] = i
#print(hash)
for wagon in wagony:
    #print(wagon,hash[wagon],akt)
    if hash[wagon] < akt:
        okrazenia += 1
        #print("UWU",akt,hash[wagon],wagon)
    akt = hash[wagon]

print(okrazenia)
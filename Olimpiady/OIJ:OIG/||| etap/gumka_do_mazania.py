def search(string,letter,number):
    i = 0
    for e,z in enumerate(string):
        if z == letter: 
            i += 1
            if i == number: return e


import string
ilosc_slow = int(input())
slowa = []
slowo = ""
for _ in range(ilosc_slow):
    slowa.append(input())
#print("y"<"x")
for znak in string.ascii_lowercase[::-1][:-1]:
    #print(znak)
    mini = float("inf")
    for i in slowa:
        mini = min(mini,i.count(znak))
    #print(mini)
    if mini > 0:
        for i in range(ilosc_slow):
            #print(slowa[i],znak)
            idx = search(slowa[i],znak,mini)
            #print(idx,slowa[i],znak)
            slowa[i] = slowa[i][idx+1:]
    slowo += znak*mini

if slowo < "bitek":
    print('bitek')
else:
    print(slowo)

print(string.ascii_lowercase[::-1][:-1])
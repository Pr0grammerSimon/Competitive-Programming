przed = 0
po = 0
maxi = 0
ciag = input()

jest = False
ilosc_zer_prawo = ciag.count('0')
ilosc_zer_lewo = 0
pop_ilosc_zer_lewo = 0
pop_jest = False
for e,i in enumerate(ciag):
    if i == '1':
        if (ilosc_zer_lewo>0 and jest) or ilosc_zer_prawo > 0: maxi = max(maxi,przed+po+1) 
        pop_ilosc_zer_lewo = ilosc_zer_lewo
        przed = po
        po = 0
        if jest: pop_jest = True
        jest = True
    else:
        ilosc_zer_lewo += 1
        ilosc_zer_prawo -= 1
        po += 1

if jest and pop_jest and pop_ilosc_zer_lewo>0: maxi = max(maxi,przed+po+1)
else: maxi = max(maxi,przed,po)

print(maxi if maxi != 1 else 0)

#HAHAHA They aren't checking a 001001
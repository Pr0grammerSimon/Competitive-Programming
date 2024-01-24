prefixy = [{'A=>T':0,'T=>A':0,'C=>T':0,'T=>C':0,'A=>C':0,'C=>A':0}]

def init(a,b):
    for i in range(len(a)):
        #print(prefixy)
        nowe_prefix = prefixy[i].copy()
        #print(f'{a[i]}=>{b[i]}')
        if f'{a[i]}=>{b[i]}' in prefixy[0]:
            nowe_prefix[f'{a[i]}=>{b[i]}'] += 1
            prefixy.append(nowe_prefix)
        else:
            prefixy.append(nowe_prefix)
def get_distance(x,y):
    AT = prefixy[y+1]["A=>T"] - prefixy[x]["A=>T"]
    TA = prefixy[y+1]["T=>A"] - prefixy[x]["T=>A"]
    AC = prefixy[y+1]["A=>C"] - prefixy[x]["A=>C"]
    CA = prefixy[y+1]["C=>A"] - prefixy[x]["C=>A"]
    CT = prefixy[y+1]["C=>T"] - prefixy[x]["C=>T"]
    TC = prefixy[y+1]["T=>C"] - prefixy[x]["T=>C"]
    
    if (AT + AC) == (CA + TA) and (TA + TC) == (AT + CT):
        wynik = min(AT,TA) + min(AC,CA) + min(CT,TC)
        wynik += 2 * abs(AT - TA)
        return wynik
    else:
        return -1
    
if __name__ == '__main__':
    _ = input()
    n, q = input().split()
    a = input()
    b = input()
    init(a, b)
    print("7abbcd01962faf1b2655df14ab1e12")
    print("OK")
    for i in range(int(q)):
        x, y = input().split()
        print(get_distance(int(x), int(y)))
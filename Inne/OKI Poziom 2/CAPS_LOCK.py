MOD = int(1e9+7)
P = 199
MAXN = int(1e6+7)
pow_P = [1 for _ in range(MAXN)]
h = [0 for _ in range(MAXN)]
ciag = input()
wzorzec = input()

len_ciag = len(ciag)
len_wzorzec = len(wzorzec)

def get_hash(l,r):
    l+=1
    r+=1
    res = (h[r] - h[l-1] + MOD) % MOD
    return (res * pow_P[len_ciag - l + 1]) % MOD


#Obliczanie potęg
for i in range(1,len_ciag+1):
    pow_P[i] = (pow_P[i-1] * P) % MOD

#Hash dla wzorca
wzorzecH = 0
for i in range(len_wzorzec):
    wzorzecH += (pow_P[i] * ord(wzorzec[i])) % MOD
wzorzecH = (wzorzecH * pow_P[len_ciag]) % MOD

#Hash dla ciagu
for i in range(len_ciag):
    h[i+1] = (h[i] + pow_P[i] * ord(ciag[i])) % MOD

ans = ciag
for i in range(len_wzorzec-1,len_ciag):
    if get_hash(i-len_wzorzec+1,i) == wzorzecH:
        for j in range(i,i-len_wzorzec,-1):
            if ans[j] <= 'Z': break
            ans = ans[:j] + chr(ord(ans[j])-32) + ans[j+1:]
print(ans)
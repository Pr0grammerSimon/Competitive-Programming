potegi_2 = [1152921504606846976, 576460752303423488, 288230376151711744, 144115188075855872, 72057594037927936, 36028797018963968, 18014398509481984, 9007199254740992, 4503599627370496, 2251799813685248, 1125899906842624, 562949953421312, 281474976710656, 140737488355328, 70368744177664, 35184372088832, 17592186044416, 8796093022208, 4398046511104, 2199023255552, 1099511627776, 549755813888, 274877906944, 137438953472, 68719476736, 34359738368, 17179869184, 8589934592, 4294967296, 2147483648, 1073741824, 536870912, 268435456, 134217728, 67108864, 33554432, 16777216, 8388608, 4194304, 2097152, 1048576, 524288, 262144, 131072, 65536, 32768, 16384, 8192, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1]
l,r = map(int,input().split())
odpowiedzi = []
while l<r:
    for i in potegi_2:
        if l%i==0:
            mnoznik = (l//i)
            if (i*(mnoznik+1)) <= r:
                odpowiedzi.append(f"{l} {i*(mnoznik+1)}")
                l=(i*(mnoznik+1))
                break

print(len(odpowiedzi))
for i in odpowiedzi:print(i)
ilosc_dni,podwyzszka = input().split()
dni = [int(i) for i in input().split()]
dp = [0]
maxxi = -1e9
for i in range(1,int(ilosc_dni)+1):
    dp.append(max(dp[i-1],maxxi+dni[i-1]-int(podwyzszka)))
    maxxi = max(maxxi,dp[i-1]-dni[i-1])
print(dp[-1])
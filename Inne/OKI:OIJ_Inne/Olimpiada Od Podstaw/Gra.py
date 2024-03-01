import collections
ilosc_liczb = int(input())
dp = collections.deque()
wejscie = input().split()
dp.append(int(wejscie[0]))
for e in range(1,ilosc_liczb):
    w = 6 if e > 5 else e
    dp.append(max([dp[i] for i in range(0,w)]) + int(wejscie[e]))
    if w == 6: dp.popleft()

print(dp[-1])
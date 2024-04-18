class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        len_prices = len(prices)
        maxi_1 = [0]*len_prices
        mini = prices[0]
        for i in range(1,len_prices):
            maxi_1[i] = max(prices[i]-mini,maxi_1[i-1])
            mini = min(mini,prices[i])

        x = prices[0]
        p = 0
        maksi = 0
        wynik = 0
        for e in range(1,len_prices):
            wynik = max(wynik,maxi_1[e],prices[e]-x+p)
            if prices[e]-maxi_1[e-1] < x-p:
                p = maxi_1[e-1]
                x = prices[e]
        return wynik
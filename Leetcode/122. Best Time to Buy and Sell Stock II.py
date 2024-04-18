class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        x = prices[0]
        p = 0
        pop_profit = 0
        for i in prices:
            pop_profit = max(pop_profit,i-x+p)
            if i-pop_profit < x-p:
                x = i
                p = pop_profit
        return pop_profit
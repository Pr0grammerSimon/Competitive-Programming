class Solution:
    def jump(self, nums: list[int]) -> int:
        len_nums = len(nums)
        wyniki = [float('inf')] * len_nums
        wyniki[0] = 0
        pop_wynik = nums[0]
        lewo = 0
        while lewo < len_nums-1:
            wynik = 0
            for i in range(1,pop_wynik+1):
                if lewo+i >= len_nums: break
                wyniki[lewo+i] = wyniki[lewo] + 1
                wynik = max(wynik,i+nums[lewo+i]-pop_wynik)
            lewo += pop_wynik
            pop_wynik = wynik
        return wyniki[-1]
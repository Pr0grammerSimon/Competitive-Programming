class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        maxi = 0
        for i in nums:
            if maxi == 0:
                liczba = i
                maxi += 1
            elif i == liczba:
                maxi += 1
            else: maxi -=1
        return liczba
#1
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k+=1
        return k
    
#2
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = len(nums)
        for i in range(len(nums)):
            if nums[i] == val:
                k-=1
                nums[i] = 101  
        nums.sort()
        return k
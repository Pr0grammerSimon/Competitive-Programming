class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k,ile,akt = 0,0,""
        for i in range(len(nums)):
            if nums[i] != akt:
                akt = nums[i]
                ile = 1
                nums[k] = nums[i]
                k+=1
            elif ile+1<=2:
                ile+=1
                nums[k] = nums[i]
                k+=1
        return k
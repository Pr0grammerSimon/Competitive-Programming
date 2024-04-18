class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        is_already = [False] * 201
        idx = 0
        for i in nums:
            if not is_already[i+100]:
                is_already[i+100] = True
                nums[idx] = i
                idx+=1
        return idx
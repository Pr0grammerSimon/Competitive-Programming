
def twoSum( nums:list[int], target: int) -> list[int]:        
    for each in nums:
        
        szukana = str(target - int(each))
        new_nums = nums[:nums.index(each)] + nums[nums.index(each) +1:]
        if str(szukana) in list(new_nums):
           return [nums.index(each), new_nums.index(szukana) +1]
           
nums = input().split()
nums = [int(i) for i in nums]
target = int(input())
print(twoSum(nums,target))
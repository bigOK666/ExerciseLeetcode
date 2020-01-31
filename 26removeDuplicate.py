class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        for item in range(len(nums)-1, -1, -1):
            if item != 0 and nums[item] == nums[item - 1]:
                nums.pop(item)
        return len(nums)

            

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        new_nums = []
        for number in nums:
            if number not in new_nums:
                new_nums.append(number)
        nums.clear()
        nums.extend(new_nums)
        return len(nums)

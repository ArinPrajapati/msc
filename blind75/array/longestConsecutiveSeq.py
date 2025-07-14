from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        max_length = 0
        current_num = 0
        current_streak = 0

        for i in num_set:
            if i - 1 not in num_set:
                current_num = i
                current_streak = 1
            while current_num + 1 in num_set:
                current_num += 1
                current_streak += 1
            if current_streak > max_length:
                max_length = current_streak

        return max_length


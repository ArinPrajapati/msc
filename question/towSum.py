from typing import List

class Solution: 
    def twoSum(self,nums:List[int],target:int)-> List[int]:

        map = {}

        for i in range(len(nums)):
            print(i)
            print(map)
            n = target - nums[i]
            print(n)
            if n not in map:
                map[nums[i]] = i
            else:
                return [map[n],i]
        return []

print(Solution().twoSum([2,7,11,15],9))

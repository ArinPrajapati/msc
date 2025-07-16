from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxArea = 0

        l,r= 0,len(height)

        while l < r:
            # min of l and r into r - 1 === area
            area = min(height[l] , height[r]) * (r - l)
            maxArea = max(maxArea,area)
            if(height[l] > height[r]):
                r-=1
            else: l+=1

        return maxArea
        

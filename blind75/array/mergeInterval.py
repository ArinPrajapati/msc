from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
       intervals.sort() 
       result = [intervals[0]]

       for i in range(1, len(intervals)):
            current = intervals[i]
            last = result[-1]
            if current[0] <= last[1]:
                temp = max(current[1], last[1])
                result[-1] = [last[0], temp]
            else:
                result.append(current)

       return result


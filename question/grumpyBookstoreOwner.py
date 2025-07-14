from typing import List

class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:

        prefixSum = 0 # non grumpy time customer count

        for i in range(len(grumpy)):
            if(grumpy[i] == 0):
                prefixSum += customers[i]

        print(prefixSum)

        tempExtra = prefixSum
        maxExtra = prefixSum

        for i in range(len(grumpy)):
            if grumpy[i] == 1:
                tempExtra += customers[i]

            if i >= minutes:
                if grumpy[i-minutes] == 1:
                    tempExtra = customers[i - minutes]
            maxExtra= max(maxExtra,tempExtra)
        return maxExtra




s = Solution()
c = [3]
g = [1]


print(s.maxSatisfied(c,g,3))




        

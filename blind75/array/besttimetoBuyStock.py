class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrince = float('inf')
        maxProfit = 0
        for price in prices:
            if price < minPrince:
                minPrince = price
            elif price - minPrince > maxProfit:
                maxProfit = price - minPrince

        return maxProfit

            

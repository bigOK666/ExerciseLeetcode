import math
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = math.inf
        max_profit = 0

        for price in prices:
            if price < min_price:
                min_price = price
            elif max_profit < price - min_price:
                max_profit = price - min_price
        return max_profit

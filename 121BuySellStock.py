class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        highest_price = max(prices)
        lowest_price = min(prices)
        if prices.index(highest_price) < prices.index(lowest_price):
            return highest_price - lowest_price
        else:
            return 0

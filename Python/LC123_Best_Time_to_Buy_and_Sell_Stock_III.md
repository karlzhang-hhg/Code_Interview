# Method 1:
Dynamic programming. Be careful about the problem statements on `at most two transactions`.

|Speed|Memory|
|-|-|
|85.24%|100.00%|

```python {.line-numbers}
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n==0:
            return 0
        pre_min, post_max = prices[0], prices[-1]
        res, pre, post = 0, [0]*n, [0]*n
        for i in range(1,n):
            pre_min, post_max = min(pre_min, prices[i]), max(post_max, prices[-i-1])
            pre[i], post[-i-1] = max(pre[i-1], prices[i]-pre_min), max(post[-i], post_max-prices[-i-1])
        return max(e1+e2 for e1, e2 in zip(pre, post))
```
# Method 1:
This method uses O(1) space and O(n) time.

|Speed|Memory|
|-|-|
|89%|100.00%|

```python {.line-numbers}
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res, res_max, res_min = nums[0], nums[0], nums[0]
        for i in range(1, len(nums)):
            res_max, res_min = max(max(res_min*nums[i], res_max*nums[i]), nums[i]), min(min(res_min*nums[i], res_max*nums[i]), nums[i])
            res = max(res, res_max)
        return res
```
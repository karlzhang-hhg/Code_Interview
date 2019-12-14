# Method 1:
The key to break this problem is to figure out the condition when we need to go left or right. Notice that the array has no duplicated element. This method is O(logn) in time-complexity.

|Speed|Memory|
|---|---|
|98.84%|100.00%|

```python {.line-numbers}
class Solution:
    def search(self, nums: List[int], targ: int) -> int:
        if len(nums)==0:
            return -1
        l, r = 0, len(nums)-1
        m = (l+r)//2
        while l<r:
            if nums[m] < targ:
                # Whe we know that
                # 1. right subarray is increasing and target number is in the range;
                # or 
                # 2. left subarray is increasing.
                # We need to go right.
                if (nums[m] <= nums[r] and targ <= nums[r]) or nums[l] <= nums[m]:
                    l = m+1
                else:
                    r = m-1
            elif nums[m] > targ:
                if (nums[l] <= nums[m] and nums[l] <= targ) or nums[m] <= nums[r]:
                    r = m-1
                else:
                    l = m+1
            else:
                break
            m = (l+r)//2     
        res = m if nums[m] == targ else -1
        return res
```

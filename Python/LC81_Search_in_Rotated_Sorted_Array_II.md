# Method 1:
The key point in this problem is that the array allows to have duplicated elements. This make the problem worst time-complexity towards O(n).

|Speed|Memory|
|---|---|
|97.46%|100.00%|

```python {.line-numbers}
class Solution:
    def search(self, nums: List[int], targ: int) -> bool:
        if len(nums)==0:
            return False
        l, r = 0, len(nums)-1
        m = (l+r)//2
        while l<r:
            if nums[m] < targ:
                # Whe we know that
                # 1. right subarray is non-decreasing and target number is in the range;
                # or 
                # 2. left subarray is non-decreasing.
                # We need to go right.

                # In order to test if the left subarray is non-decreasing, we need to go through all the element if elements at both ends equal to each other. This make the algorithm worst case O(n).
                mm = m
                while nums[l]==nums[mm] and l<mm:
                    mm-=1
                if (nums[m] <= nums[r] and targ <= nums[r]) or nums[l]<nums[m] or l==mm:
                    l = m+1
                else:
                    r = m-1
            elif nums[m] > targ:
                mm = m
                while nums[mm]==nums[r] and mm<r:
                    mm+=1
                if (nums[l] <= nums[m] and nums[l] <= targ) or nums[m]<nums[r] or mm==r:
                    r = m-1
                else:
                    l = m+1
            else:
                break
            m = (l+r)//2
        res = True if nums[m] == targ else False
        return res
```

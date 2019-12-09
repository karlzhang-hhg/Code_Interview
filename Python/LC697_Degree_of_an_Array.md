# Method 1:
O(n) algorithm.

|Speed|Memory|
|-|-|
|17.76%|27.27%|

```python {.line-numbers}
from collections import Counter
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        pos = {}
        n = len(nums)
        res = n
        counter = Counter()
        deg = 0
        for num in nums:
            counter[num] += 1
            deg = max(deg, counter[num])
            
        for i in range(n):
            n1, n2 = nums[i], nums[-i-1]
            if counter[n1]==deg:
                if n1 not in pos:
                    pos[n1] = [i, -1]
                else:
                    tmp = pos[n1]
                    if tmp[0]<0:
                        if tmp[1]>=0:
                            res = min(res, tmp[1]-i+1)
                        tmp[0] = i
            if counter[n2]==deg:
                if n2 not in pos:
                    pos[n2] = [-1, n-i-1]
                else:
                    tmp = pos[n2]
                    if tmp[1]<0:
                        if tmp[0]>=0:
                            res = min(res, n-i-tmp[0])
                        tmp[1]=n-i-1
        return res
```

Clearer version.

|Speed|Memory|
|-|-|
|26.03%|27.27%|


```python {.line-numbers}
from collections import Counter
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        pos = {}
        n = len(nums)
        res = n
        counter = Counter()
        deg = 0
        for i, (n1,n2) in enumerate(zip(nums, nums[::-1])):
            counter[n1] += 1
            deg = max(deg, counter[n1])
            if n1 not in pos:
                pos[n1] = [i, -1]
            elif pos[n1][0]<0:
                pos[n1][0]=i
            if n2 not in pos:
                pos[n2] = [-1, n-i-1]
            elif pos[n2][1]<0:
                pos[n2][1]=n-i-1
        
        for v, p in pos.items():
            if counter[v]==deg:
                res = min(res, p[1]-p[0]+1)
        
        return res
```

Faster version, because we use vectorized calculation instead of iterative method.

|Speed|Memory|
|-|-|
|82.6%|27.27%|

```python {.line-numbers}
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        pos = {}
        n = len(nums)
        res = n
        counter = {}
        deg = 0
        for i, (n1,n2) in enumerate(zip(nums, nums[::-1])):
            counter[n1] = counter.get(n1, 0) +1
            if n1 not in pos:
                pos[n1] = [i, -1]
            elif pos[n1][0]<0:
                pos[n1][0]=i
            if n2 not in pos:
                pos[n2] = [-1, n-i-1]
            elif pos[n2][1]<0:
                pos[n2][1]=n-i-1
        deg = max(counter.values())
        for v, p in pos.items():
            if counter[v]==deg:
                res = min(res, p[1]-p[0]+1)
        
        return res
```


# Method 2:
Leetcode solution. Using dictionary with value as primitive type requires less time and less space than using object as value.

|Speed|Memory|
|-|-|
|97.59%|81.82%|


```python {.line-numbers}
class Solution(object):
    def findShortestSubArray(self, nums):
        left, right, count = {}, {}, {}
        for i, x in enumerate(nums):
            if x not in left: left[x] = i
            right[x] = i
            count[x] = count.get(x, 0) + 1

        ans = len(nums)
        degree = max(count.values()) # This step use vectorized calculation.
        for x in count:
            if count[x] == degree:
                ans = min(ans, right[x] - left[x] + 1)

        return ans
```


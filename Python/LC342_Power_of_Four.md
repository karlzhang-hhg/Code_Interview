# Method 1:
Use bit operation can simplify programming and minimize speed and memory as much as possible.

|Speed|Memory|
|-|-|
|99.24%|100.00%|

```python {.line-numbers}
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        # This number is the largest signed 32-bit number that has 1 on all odd binary digit and 0 ow.
        mask = 715827882
        return num>0 and (num & (num-1))==0 and (mask & num)==0
```


# Method 2:
Use log2 function.

|Speed|Memory|
|-|-|
|99.24%|100.00%|

```python {.line-numbers}
from math import log2
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        return num > 0 and log2(num) % 2 == 0
```
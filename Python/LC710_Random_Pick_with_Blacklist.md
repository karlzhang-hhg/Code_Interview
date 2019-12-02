# Method 1:
This method use only one `random.randarange(stop)` every call of `.pick`. This method has time complexity O(BlogB), and space complexity O(B).

|Speed|Memory|
|-|-|
|98.21%|100.00%|

```python {.line-numbers}
class Solution:

    def __init__(self, N: int, blacklist: List[int]):
        self.size = N-len(blacklist)
        blacklist.sort()
        idx = bisect.bisect_left(blacklist, self.size)
        self.mem = {}
        nnum, j = self.size, idx
        for i in range(idx):
            while j<len(blacklist) and nnum==blacklist[j]:
                nnum+=1
                j+=1
            self.mem[blacklist[i]]=nnum
            nnum+=1

    def pick(self) -> int:
        rnum = random.randrange(self.size)
        if rnum in self.mem:
            rnum = self.mem[rnum]
        return rnum
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(N, blacklist)
# param_1 = obj.pick()
```

# Method 2:
This method has time complexity O(B) and space complexity O(B). I used `collections.OrderedDict()` to stored the key-value pairs for those numbers that are blacklisted.

|Speed|Memory|
|-|-|
|95.34%|20.00%|

```python {.line-numbers}
from collections import OrderedDict
class Solution:

    def __init__(self, N: int, blacklist: List[int]):
        self.size = N-len(blacklist)
        self.mem = OrderedDict()
        b_set = set()
        for num in blacklist:
            if num<self.size:
                self.mem[num]=0
            else:
                b_set.add(num)
        
        idx = 0
        items = list(self.mem.items())
        for num in range(self.size, N):
            if num not in b_set:
                key = items[idx][0]
                idx += 1
                self.mem[key]=num
            num+=1

    def pick(self) -> int:
        rnum = random.randrange(self.size)
        if rnum in self.mem:
            rnum = self.mem[rnum]
        return rnum
```

Instead of using `collections.OrderedDict`, I use ordinary dictionary. This uses less memory than `OrderedDict`.

|Speed|Memory|
|-|-|
|96.42%|20.00%|

```python {.line-numbers}
from collections import OrderedDict
class Solution:

    def __init__(self, N: int, blacklist: List[int]):
        self.size = N-len(blacklist)
        self.mem = {}
        key_ls = []
        b_set = set()
        for num in blacklist:
            if num<self.size:
                key_ls.append(num)
            else:
                b_set.add(num)
        
        idx = 0
        for num in range(self.size, N):
            if num not in b_set:
                key = key_ls[idx]
                idx += 1
                self.mem[key]=num
            num+=1

    def pick(self) -> int:
        rnum = random.randrange(self.size)
        if rnum in self.mem:
            rnum = self.mem[rnum]
        return rnum
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(N, blacklist)
# param_1 = obj.pick()
```
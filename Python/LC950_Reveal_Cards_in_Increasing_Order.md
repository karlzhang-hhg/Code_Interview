# Method 1:
Iterative method. Be careful about the index and the order of operation. When we reverse the operations, the last step should not have moving the last card to the top.

|Speed|Memory|
|---|---|
|99.62%|100.00%|

```python {.line-numbers}
# The following algorithm theoretically have complexity O(n^2).
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort()
        res = [deck[-1]]
        for c in deck[-2::-1]:
            res.append(res.pop(0))
            res.append(c)
        return res[::-1]
```

# Method 2:
Leetcode solution. This method have complexity strictly O(nlogn). And it is more intuitive.

|Speed|Memory|
|---|---|
|99.62%|100.00%|

```python {.line-numbers}
class Solution(object):
    def deckRevealedIncreasing(self, deck):
        N = len(deck)
        index = collections.deque(range(N))
        ans = [None] * N

        for card in sorted(deck):
            ans[index.popleft()] = card
            if index:
                index.append(index.popleft())

        return ans
```
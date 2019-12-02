# Method 1:
Use list as array. This can save time and space. If using dictionary, the space and speed would both compromised.

|Speed|Memory|
|-|-|
|69.09%|50.00%|


```python {.line-numbers}
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # mem = [[-1]*(len(p)+1) for i in range(len(s)+1)]
        mem = {}
        def helper(i, j):
            # if mem[i][j]!=-1:
                # return bool(mem[i][j])
            if (i,j) in mem:
                return bool(mem[(i,j)])
            if j==len(p):
                res = (i==len(s))
            elif i==len(s):
                res = (p[j]=='*' and helper(i,j+1))
            elif p[j]=='?':
                res = helper(i+1, j+1)
            elif p[j]=='*':
                res = helper(i, j+1) or helper(i+1, j)
            else:
                res = s[i]==p[j] and helper(i+1, j+1)
            # mem[i][j] = res
            mem[(i,j)] = res
            return res
        return helper(0,0)
```

# Method 2:
Rule out the extra `*` first. Then, we can save some time.

|Speed|Memory|
|-|-|
|71.96%|50.00%|

```python {.line-numbers}
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if len(p)>0:
            p1=[]
            for i in range(len(p)):
                if len(p1)>0 and p[i]=='*' and p1[-1]=='*':
                    continue
                else:
                    p1.append(p[i])
            if len(p1)<len(p): p = ''.join(p1)
            print(p)
                
        mem = [[-1]*(len(p)+1) for i in range(len(s)+1)]
        def helper(i, j):
            if mem[i][j]!=-1:
                return bool(mem[i][j])
            if j==len(p):
                res = (i==len(s))
            elif i==len(s):
                res = (p[j]=='*' and helper(i,j+1))
            elif p[j]=='?':
                res = helper(i+1, j+1)
            elif p[j]=='*':
                res = helper(i, j+1) or helper(i+1, j)
            else:
                res = s[i]==p[j] and helper(i+1, j+1)
            mem[i][j] = res
            return res
        return helper(0,0)
```
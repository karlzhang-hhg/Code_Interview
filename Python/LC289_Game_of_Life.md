# Method 1:
This is in-place method. And I avoid re-calculating the number of neighbors. If the matrix is infinite large, how can we do this problem. I initially thought I should use periodic boundary condition. However, after looking the solution, I realized that I thought it wrong. I should think it in terms of scalability. The solution basically is to treat it as sparse matrix or only read three rows into memory.

|Speed|Memory|
|-|-|
|99.36%|100.00%|

```python {.line-numbers}
class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if len(board)==0 or len(board[0])==0:
            return
        m, n = len(board), len(board[0])
        def check(i, j):
            return i>=0 and i<m and j>=0 and j<n
        def count(i,j):
            cnt = 0
            for k in range(-1,2):
                if check(i, j+k) and (board[i][j+k]==1 or board[i][j+k]==-2):
                    cnt += 1
            return cnt
        def update(i,j,r_cnt):
            cnt = sum(r_cnt)-board[i][j]
            if cnt<2 and board[i][j]==1:
                board[i][j]=-2
            elif cnt>3 and board[i][j]==1:
                board[i][j]=-2
            elif cnt==3 and board[i][j]==0:
                board[i][j]=-1
        for j in range(n):
            r_cnt = [0]
            r_cnt.extend([count(0,j), count(1,j)])
            for i in range(m):
                update(i,j,r_cnt)
                r_cnt.pop(0)
                r_cnt.append(count(i+2,j))
        for i in range(m):
            for j in range(n):
                if board[i][j]==-1: board[i][j]=1
                if board[i][j]==-2: board[i][j]=0
```


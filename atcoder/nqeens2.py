from typing import List

class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:

        cols = set() # maintain the cols 
        posDig = set() # r + c
        negDiag = set() # r - c

        res = []
        board = ["." *n  for _ in range(n)]
        
        def backTrack(row): 
            if row == n: 
                res.append(board[:])
                return
            for col in range(n):
                if col in cols or (row - col) in negDiag or (row + col) in posDig:
                    continue

                board[row] = board[row][:col] + "Q" + board[row][col+1:]
                cols.add(col)
                negDiag.add(row-col)
                posDig.add(row + col)

                backTrack(row + 1)

                board[row] = "." * n
                cols.remove(col)
                negDiag.remove(row-col)
                posDig.remove(row + col)

        backTrack(0)
        return res



s = Solution()

print(s.solveNQueens(4))

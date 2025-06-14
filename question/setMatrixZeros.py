from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        m = len(matrix[0])

        

        for i in range(1,n):
            for j in range(1,m):
                if(matrix[i][j] == 0):
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
        for i in range(1,n):
            for j in range(1,m):
                if(matrix[0][j] == 0 or matrix[i][0] == 0):
                    matrix[i][j] = 0;

        fc = False
        for i in range(n):
            if(matrix[i][0] == 0):
                fc=True
        fr = False
        for i in range(m):
            if(matrix[0][i] == 0):
                fr = True

        if fc:
            for i in range(n):
                matrix[i][0] = 0

        if fr:
            for i in range(m):
                matrix[0][i] = 0


        


sol = Solution()        
sol.setZeroes([[1,1,1],[1,0,1],[1,1,1]])



class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        dy = [0,0,-1,1]
        dx = [1,-1,0,0]
        len_y = len(land)
        len_x = len(land[0])
        odwiedzone = [[False for _ in range(len_x)] for _ in range(len_y)]
        def dfs(y_,x_):
            stos = collections.deque([[y_,x_]])
            maxi_y = y_
            maxi_x = x_
            while stos:
                y,x = stos.popleft()
                maxi_y = max(maxi_y,y)
                maxi_x = max(maxi_x,x)
                for i in range(4):
                    if 0 <= (y+dy[i]) < len_y and 0 <= (x+dx[i]) < len_x and not odwiedzone[y+dy[i]][x+dx[i]] and land[y+dy[i]][x+dx[i]]:
                        odwiedzone[y+dy[i]][x+dx[i]] = True
                        stos.append([y+dy[i],x+dx[i]])
            return maxi_y,maxi_x
        
        wynik = []
        for y in range(len_y):
            for x in range(len_x):
                if not odwiedzone[y][x] and land[y][x] == 1:
                    y_2,x_2 = dfs(y,x)
                    wynik.append([y,x,y_2,x_2])

        return wynik

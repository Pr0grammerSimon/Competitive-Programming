class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        wynik = 0
        len_y = len(grid)
        len_x = len(grid[0])
        dy = [1,-1,0,0]
        dx = [0,0,1,-1]
        for y in range(len_y):
            for x in range(len_x):
                if grid[y][x] == 1:
                    for i in range(4):
                        if y+dy[i] >= len_y or y+dy[i] < 0 or x+dx[i]>=len_x or x+dx[i]<0:
                            wynik += 1
                            continue
                        elif grid[y+dy[i]][x+dx[i]] == 0: wynik += 1
        return wynik
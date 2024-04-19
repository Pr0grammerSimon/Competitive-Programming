class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        dy = [0,0,-1,1]
        dx = [1,-1,0,0]
        len_y = len(grid)
        len_x = len(grid[0])
        odwiedzone = [[False for _ in range(len_x)] for _ in range(len_y)]
        wynik = 0
        for y in range(len_y):
            for x in range(len_x):
                if grid[y][x] == "1" and not odwiedzone[y][x]:
                    stos = collections.deque([[y,x]])
                    wynik += 1
                    odwiedzone[y][x] = True
                    while stos:
                        p_y,p_x = stos.popleft()
                        for i in range(4):
                            if  -1 < dy[i]+p_y < len_y and -1 < dx[i]+p_x < len_x and grid[p_y+dy[i]][p_x+dx[i]] == "1" and not odwiedzone[p_y+dy[i]][p_x+dx[i]]:
                                stos.append([dy[i]+p_y,dx[i]+p_x])
                                odwiedzone[dy[i]+p_y][dx[i]+p_x] = True
        return wynik
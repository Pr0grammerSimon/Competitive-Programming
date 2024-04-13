#1

class Solution:
    def minimumTime(self, n: int, edges: list[list[int]], disappear: list[int]) -> list[int]:
        graph = {i:[] for i in range(n)}
        mini = [-1 for i in range(n)]
        for i in edges:
            graph[i[0]].append([i[1],i[2]])
            graph[i[1]].append([i[0],i[2]])
        my_queue = [(0,0)]
        while my_queue :
            point = heapq.heappop(my_queue)
            if mini[point[1]] != -1: continue
            mini[point[1]] = point[0]
            for neighbour in graph[point[1]]:
                if mini[neighbour[0]] == -1 and point[0]+neighbour[1] < disappear[neighbour[0]]:
                    heapq.heappush(my_queue,(point[0]+neighbour[1],neighbour[0]))
        return mini
    
#2
    
import queue 
class Solution:
    def minimumTime(self,n: int, edges: list[list[int]], disappear: list[int]) -> list[int]:
        graph = {i:[] for i in range(n)}
        mini = [-1 for i in range(n)]
        for i in edges:
            graph[i[0]].append([i[1],i[2]])
            graph[i[1]].append([i[0],i[2]])
        my_queue = queue.PriorityQueue()
        my_queue.put((0,0))
        while my_queue.qsize() > 0:
            point = my_queue.get()
            print(point)
            if mini[point[1]] != -1: continue
            mini[point[1]] = point[0]
            for neighbour in graph[point[1]]:
                if (mini[neighbour[0]] == -1 ) and point[0]+neighbour[1] < disappear[neighbour[0]]:
                    my_queue.put((point[0]+neighbour[1],neighbour[0]))
        return mini
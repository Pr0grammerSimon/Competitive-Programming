class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        h = len(matrix)
        w = len(matrix[0])
        pop_wysokosci = [0 for _ in range(w+1)]
        wysokosci = []
        wynik = 0
        for y in range(h):
            kolejka = collections.deque()
            for x in range(w+1):
                if x == w: i = 0
                else:
                    if matrix[y][x] == "1":
                        wysokosci.append(pop_wysokosci[x]+1)
                    else:
                        wysokosci.append(0)
                    i = wysokosci[x]
                ostatni_punkt = x
                while len(kolejka) > 0 and kolejka[0][0] > i:
                    punkt = kolejka.popleft()
                    wynik = max(wynik,punkt[0]*(x-punkt[1]))
                    ostatni_punkt = min(ostatni_punkt,punkt[1])
                if len(kolejka) == 0 or kolejka[0][0] != i:
                    kolejka.appendleft([i,ostatni_punkt])
            pop_wysokosci = wysokosci
            wysokosci = []
        return wynik

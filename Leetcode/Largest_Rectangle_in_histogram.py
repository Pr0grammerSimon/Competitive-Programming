class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights.append(0)
        kolejka = collections.deque()
        wynik = 0
        for e,i in enumerate(heights):
            ostatni_punkt = e
            while len(kolejka) > 0 and kolejka[0][0] > i:
                punkt = kolejka.popleft()
                wynik = max(wynik,punkt[0]*(e-punkt[1]))
                ostatni_punkt = min(ostatni_punkt,punkt[1])
            if len(kolejka) == 0 or kolejka[0][0] != i:
                kolejka.appendleft([i,ostatni_punkt])
        return wynik
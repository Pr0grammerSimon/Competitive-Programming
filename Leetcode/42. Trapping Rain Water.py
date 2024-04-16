class Solution:
    def trap(self, height: List[int]) -> int:
        stos = collections.deque()
        wynik = 0
        for e,i in enumerate(height):
            if i == 0: continue
            while len(stos) > 0 and stos[-1][2] <= i:
                h = stos.pop()
                wynik += (e-h[0]-1)*min(i,h[2]-h[1])   
            if len(stos) > 0:
                h=stos[-1]
                wynik += (e-h[0]-1)*(i-h[1])  
                stos[-1][1] = i
            stos.append([e,0,i])
        return wynik
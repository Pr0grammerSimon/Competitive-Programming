#1 
class Solution:

    def longestPalindrome(self, s: str) -> str:
        length_s = len(s)
        wynik = [0,0]
        def check(e1,e2):
            while e1-1 > -1 and e2+1 < length_s and s[e1-1] == s[e2+1]:
                e1-=1
                e2+=1
            return e1,e2
        for i in range(length_s):
            w = check(i,i)
            if wynik[1]-wynik[0]+1 < w[1]-w[0]+1: wynik = w
        for i in range(length_s-1):
            if s[i] == s[i+1]: 
                w = check(i,i+1)
                if wynik[1]-wynik[0]+1 < w[1]-w[0]+1: wynik = w
        return s[wynik[0]:wynik[1]+1]
    
#2 Manacher's algorithm
    
class Solution:

    def longestPalindrome(self, s: str) -> str:
        s_other = "#" + "#".join(s) + "#"
        length_n = len(s_other)
        scores = [0] * length_n
        center = radius = 0
        for i in range(length_n):
            mirror = 2*center-i

            if i < radius:
                scores[i] = min(radius-i,scores[mirror])

            while i+1+scores[i] < length_n and i-1-scores[i] > -1 and s_other[i+1+scores[i]] == s_other[i-1-scores[i]]:
                scores[i] += 1
            
            if i+scores[i] > radius:
                radius = scores[i]+i
                center=i
        length_max = max(scores)
        center = scores.index(length_max)
        start = (center-length_max)//2
        return s[start:start+length_max]
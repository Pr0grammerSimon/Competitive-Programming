class Solution:
    def candy(self, ratings: list[int]) -> int:
        len_ratings = len(ratings)
        wyniki = [1]*len_ratings
        for i in range(1,len_ratings):
            if ratings[i] > ratings[i-1]:
                wyniki[i] = wyniki[i-1]+1
        for i in range(len_ratings-2,-1,-1):
            if ratings[i] > ratings[i+1]:
                wyniki[i] = max(wyniki[i+1]+1,wyniki[i])
        return sum(wyniki)
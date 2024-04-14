class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        dp = [0]
        word_length = len(word)
        result = 0
        for e,i in enumerate(sequence):
            wynik = 0
            if e+1 >= word_length:
                if sequence[e-word_length+1:e+1] == word: 
                    wynik += 1 
                    wynik += dp[e-word_length+1]
            result = max(result,wynik)
            dp.append(wynik)
        return result

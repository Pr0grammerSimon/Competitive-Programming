import sys
def solution(pozycja,memo=set()):
    memo.add(pozycja)
    #print(pozycja)
    if znaki[pozycja] == "X": return 0
    if pozycja == 99: return 1
    if pozycja - 10 > 0 and (pozycja-10 not in memo):
        if solution(pozycja-10,memo) == 1: return 1
    if pozycja + 10 < 100 and (pozycja+10 not in memo):
        if solution(pozycja+10,memo) == 1: return 1
    if pozycja % 10 != 0 and (pozycja-1 not in memo):
        if solution(pozycja-1,memo) == 1: return 1
    if (pozycja + 1) % 10 != 0 and (pozycja+1 not in memo):
        if solution(pozycja+1,memo) == 1: return 1
    return 0
for i in sys.stdin:
    znaki = i
    print(solution(0,set()))

    
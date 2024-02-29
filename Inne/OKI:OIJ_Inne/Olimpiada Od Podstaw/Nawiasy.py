import collections
Q = int(input())
for _ in range(Q):
    kolejka = collections.deque()
    dobry = True
    ciag = input()
    try:
        for znak in ciag:
            if znak == ")":
                znaczek = kolejka.pop()
                if znaczek != '(':
                    dobry = False
                    break
            elif znak == "}":
                znaczek = kolejka.pop()
                if znaczek != '{':
                    dobry = False
                    break
            elif znak == "]":
                znaczek = kolejka.pop()
                if znaczek != '[':
                    dobry = False
                    break
            else:
                kolejka.append(znak)
    except:
        dobry = False
    if len(kolejka) > 0: dobry = False
    if dobry: print("TAK")
    else: print("NIE")
string = input()
hash = {"O":0,"I":0,"J":0,"E":0}

olimpiady = ['F','F','F']

for i in string:
    if 'F' not in set(olimpiady): break
    if i in {'O','I','J','E'}:
        hash[i] +=1
        if hash["O"] > 0 and hash["I"] > 0:
            if hash["J"] > 0:
                olimpiady[0] = 'T'
                if hash["E"] > 0:
                    olimpiady[1] = 'T'
            if hash['I'] > 1:
                olimpiady[2] = 'T'

print(''.join(olimpiady))
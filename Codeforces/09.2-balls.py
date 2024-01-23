string = input()
label = [[string[0],0]]
actual_index = 0
for i in string:
    if i == label[actual_index][0]:
        label[actual_index][1] += 1
    else:
        actual_index += 1
        label.append([i,1])
dlugosc = len(label)
mozna = False
srodek = (1 + dlugosc) // 2 - 1
if dlugosc % 2 == 1:
    #print(srodek)
    mozna = True
    if label[srodek][1] < 2:
        mozna = False
    else:   
        n = 1
        while n <= srodek:
            if label[srodek-n][1] + label[srodek+n][1] > 2 and label[srodek+n][0] == label[srodek-n][0]:
                n+=1
            else:
                mozna = False
                break
if not mozna:
    print(0)
else:
    print(label[srodek][1]+1)
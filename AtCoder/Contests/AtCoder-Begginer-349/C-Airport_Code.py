word_s = input()
word_t = input().lower()
length = 3
if word_t[2] == "x": length = 2
act_pos = 0
for i in word_s:
    if i == word_t[act_pos]:
        act_pos += 1
        if act_pos == length: break
print("Yes" if length == act_pos else "No")
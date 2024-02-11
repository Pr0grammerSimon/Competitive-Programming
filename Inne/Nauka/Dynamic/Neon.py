podciag_1,podciag_2 = input().split()

pop_tablica = [0 for _ in range(len(podciag_1)+1)]
for i in range(1,len(podciag_2)+1):
    nowa_tablica = [0 for _ in range(len(podciag_1)+1)]
    for j in range(1,len(podciag_1)+1):
        #print(podciag_1[j-1],podciag_2[j-1])
        if podciag_1[j-1] == podciag_2[i-1]:
            nowa_tablica[j] = pop_tablica[j-1]+1
        else:
            nowa_tablica[j] = max(pop_tablica[j],nowa_tablica[j-1])
    #print(pop_tablica,nowa_tablica)
    pop_tablica = nowa_tablica

print(nowa_tablica[-1])
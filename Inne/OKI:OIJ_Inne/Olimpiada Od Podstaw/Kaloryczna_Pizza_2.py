h,w = input().split()
h,w = int(h),int(w)
wysokoscie = [[0 for _ in range(w+1)] for _ in range(h+1)]
sumy = [[0 for _ in range(w+1)] for _ in range(h+1)]
for y in range(1,h+1):
    wiersz = [int(i) for i in input().split()]
    for x in range(1,w+1):
        wysokoscie[y][x] = wysokoscie[y-1][x] + wiersz[x-1]
        sumy[y][x] = sumy[y][x-1] + wysokoscie[y][x]
#print(wysokoscie)
#print(sumy)
ilosc_zapytan = int(input())
for _ in range(ilosc_zapytan):
    y_1,x_1,y_2,x_2 = input().split()
    print(sumy[int(y_2)][int(x_2)]-sumy[int(y_1)-1][int(x_2)]-(sumy[int(y_2)][int(x_1)-1]-sumy[int(y_1)-1][int(x_1)-1]))
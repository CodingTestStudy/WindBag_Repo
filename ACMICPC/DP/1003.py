N = int(input())

input_lst = []

for i in range(N):
    input_lst.append(int(input()))

lst = [[0, 0] for i in range(41)]

lst[0] = [1, 0]
lst[1] = [0, 1]

for i in range(2, max(input_lst) + 1):
    lst[i][0] = lst[i - 1][0] + lst[i - 2][0]
    lst[i][1] = lst[i - 1][1] + lst[i - 2][1]


for i in range(N):
    print(str(lst[input_lst[i]][0]) + " " + str(lst[input_lst[i]][1]))
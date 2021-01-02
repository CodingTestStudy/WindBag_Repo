# 10844.py 쉬운 계단 수

N = int(input())

lst = [[0] + [1 for i in range(9)]]

for i in range(N - 1):
    tmp = [0 for i in range(10)]

    tmp[1] += lst[i][0]
    for j in range(1, 9):
        tmp[j - 1] += lst[i][j] 
        tmp[j + 1] += lst[i][j]
    tmp[8] += lst[i][9]

    lst.append(tmp)


print(sum(lst[N - 1]) % 1000000000)
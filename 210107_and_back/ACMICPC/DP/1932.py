# 1932.py 정수 삼각형

n = int(input())

lst = []

for i in range(n):
    lst.append(list(map(int, input().split())))


for i in range(n - 1):
    lst[i + 1][0]   = lst[i + 1][0] + lst[i][0]
    lst[i + 1][1]   = lst[i + 1][1] + lst[i][0]

    for j in range(1, i + 1):
        lst[i + 1][j]       = max(lst[i + 1][j], lst[i + 1][j] - lst[i][j - 1] + lst[i][j])
        lst[i + 1][j + 1]   = max(lst[i + 1][j + 1], lst[i + 1][j + 1] + lst[i][j])

print(max(lst[n - 1]))
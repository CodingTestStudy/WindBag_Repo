# 1149.py RGB거리

N = int(input())

lst = []

three_val = list(map(int, input().split()))

lst.append([three_val[0], three_val[1], three_val[2]])

for i in range(1, N):
    three_val = list(map(int, input().split()))
    lst.append([three_val[0] + min(lst[i - 1][1], lst[i - 1][2]),
                three_val[1] + min(lst[i - 1][0], lst[i - 1][2]),
                three_val[2] + min(lst[i - 1][0], lst[i - 1][1])])

print(min(lst[N - 1]))
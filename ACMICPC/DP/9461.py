# 9461.py

# 아이디어 : 처음만 조금 불규칙하고 이후로는 규칙적

T = int(input())

lst = []

ans = [0 for i in range(100)]
ans[0] = 1
ans[1] = 1
ans[2] = 1
ans[3] = 2
ans[4] = 2
ans[5] = 3
ans[6] = 4

for i in range(T):
    lst.append(int(input()))

for i in range(5, max(lst)):
    ans[i] = ans[i - 1] + ans[i - 5]

for i in lst:
    print(ans[i - 1])
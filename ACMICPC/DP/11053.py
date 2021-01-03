# 11053.py 가장 긴 증가하는 부분 수열

N = int(input())

lst = list(map(int, input().split()))

ans = [1 for i in range(N)]

for i in range(1, N):
    tmp = []
    for j in range(i):
        if lst[j] < lst[i]:
           tmp.append(ans[j])

    if tmp: 
        ans[i] = 1 + max(tmp)

print(max(ans))
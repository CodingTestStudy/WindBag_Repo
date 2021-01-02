# 2156.py 포도주 시식

# 포도주가 1 ~ n 개 까지 있을 때, 임의의 k 번째 포도주가 가질 수 있는 경우의 수 는 세 가지다.
# 1. 선택되지 않음
# 2. 첫번째 포도주임
# 3. 두번째 포도주임

# ans[k] 가 k번째 포도주 까지의 최대합일때, 
# 1. 에서 k번째 포도주가 선택되지 않았으므로 ans[k] = ans[k-1]이다.
# 2. 에서 k번째 포도주는 첫 번째 포도주이므로 k-1 번째 포도주는 선택되지 않는다. ans[k] = ans[k-2] + lst[k] 이다.
# 3. 에서 k번째 포도주는 두 번째 포도주이므로 k-1 번째 포도주는 무조건 선택되고 k-2번째 포도주는 선택되지 않는다. 따라서 ans[k] = ans[k-3] + lst[k-1] + lst[k] 

n = int(input())

lst = []

for i in range(n):
    lst.append(int(input()))

ans = [0 for i in range(n)]

if n == 1:
    print(lst[0])
elif n == 2:
    print(lst[1] + lst[0])
else:
    ans[0] = lst[0]
    ans[1] = lst[1] + lst[0]
    ans[2] = sum(lst[0:3]) - min(lst[0:3])

    for i in range(3, n):
        ans[i] = max(ans[i - 1], ans[i - 2] + lst[i], ans[i - 3] + lst[i] + lst[i - 1])

    print(ans[n - 1])
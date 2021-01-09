N = int(input())

lst = [0 for i in range(N // 2)]

lst[0] = 1
lst[1] = 1

for i in range(2, N + 1):
    lst[i] = i * lst[i - 1]

n = 0
cnt = 0

while(n <= N):
    cnt += lst[N] // lst[n] * lst[N-n]

    n += 2

print(cnt)
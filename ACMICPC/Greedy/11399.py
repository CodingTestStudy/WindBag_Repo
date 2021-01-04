N = int(input())

lst = list(map(int, input().split()))

lst.sort()

waiting = [0 for i in range(N)]

for i in range(N):
    time = lst[i]

    for j in range(i, N):
        waiting[j] += time

print(sum(waiting))
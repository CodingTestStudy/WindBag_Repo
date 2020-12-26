from collections import deque

queue = deque()

cnt = 0

N, M = map(int, input().split())

MAP = []

for i in range(N):
    MAP.append(list(map(int, input())))

def bfs(i, j):
    global MAP, queue, cnt

    queue.append((i, j))

    while(queue):
        x, y = queue.popleft()
        MAP[x][y] = 1

        if x+1 < N and MAP[x+1][y] == 0:
            queue.append((x+1, y))
        if y-1 > -1 and MAP[x][y-1] == 0:
            queue.append((x, y-1))
        if y+1 < M and MAP[x][y+1] == 0:
            queue.append((x, y+1))

    cnt+=1

for i in range(N):
    for j in range(M):
        if MAP[i][j] == 0:
            bfs(i, j)

print(cnt)
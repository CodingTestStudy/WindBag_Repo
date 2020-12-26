from collections import deque

N, M = map(int, input().split())

queue = deque()

MAP = []

for i in range(N):
    MAP.append(list(map(int, input())))

def bfs(i, j):
    global MAP
    queue.append((i, j, 1))

    while(True):
        x, y, n = queue.popleft()
        MAP[x][y] = 0

        if x == N-1 and y == M-1:
            return n

        if x+1 < N and MAP[x+1][y] == 1:
            queue.append((x+1, y, n+1))
        if x-1 > -1 and MAP[x-1][y] == 1:
            queue.append((x-1, y, n+1))
        if y+1 < M and MAP[x][y+1] == 1:
            queue.append((x, y+1, n+1))
        if y-1 > -1 and MAP[x][y-1] == 1:
            queue.append((x, y-1, n+1))
    
    return yes

print(bfs(0, 0))
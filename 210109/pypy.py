import itertools
import math

N = int(input())

food = []

knight, bishop, rook = map(int, input().split())

x_start, y_start = map(int, input().split())

K = int(input())

for i in range(K):
    x, y = map(int, input().split())
    food.append((x, y))

possible = list(itertools.permutations(food, K))
possible = list(map(list, possible))
for i in possible:
    i.insert(0, (x_start, y_start))

lst = []

for order in possible:
    cnt = 0
    for i in range(len(order) - 1):
        #check bishop
        if abs(order[i][0] - order[i + 1][0]) == abs(order[i][1] - order[i + 1][1]):
            cnt += bishop
            continue
        # check knight
        elif (abs(order[i][0] - order[i + 1][0]) == 1 and abs(order[i][1] - order[i + 1][1]) == 2) or(abs(order[i][0] - order[i + 1][0]) == 2 and abs(order[i][1] - order[i + 1][1]) == 1): 
            cnt += knight
            continue
        # check rook
        elif (order[i][0] == order[i + 1][0]) or (order[i][1] == order[i + 1][1]):
            cnt += rook
            continue
        else:
            cnt += min(2*rook, 2*bishop if ((order[i][0] + order[i][1]) % 2) == ((order[i + 1][0] + order[i + 1][1]) % 2) else 2*bishop + min(knight, rook))
            
    lst.append(cnt)

print(min(lst))
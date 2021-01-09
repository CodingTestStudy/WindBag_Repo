n = int(input())

lst = [0 for i in range(91)]

lst[0] = 0
lst[1] = 1

for i in range(2, n + 1):
    lst[i] = lst[i-1] + lst[i - 2]

print(lst[n])
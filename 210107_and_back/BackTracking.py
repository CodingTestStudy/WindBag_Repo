# 2020-12-27 Back tracking Problems~

N, M = map(int, input().split())

def select(n, lst, string, m):
    if n == M:
        for i in range(m, len(lst)):
            if lst[i] == 0:
                print(string + str(i + 1))

    else:
        for i in range(m, len(lst)):
            if lst[i] == 0:
                select(n + 1, lst, string + str(i + 1) + " ", i)

lst = [0 for j in range(N)]
select(1, lst, "", 0)
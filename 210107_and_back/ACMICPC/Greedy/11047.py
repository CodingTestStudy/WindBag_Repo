N = int(input())

ans = 0

road = list(map(int, input().split()))
price = list(map(int, input().split()))

end = N - 1

while end != 0:
    start = price.index(min(price[:end]))
    ans += price[start] * sum(road[start:end])
    end = start

print(ans)
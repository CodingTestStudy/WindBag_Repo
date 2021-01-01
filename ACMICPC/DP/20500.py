# 20500.py Ezreal 여눈부터 가네 ㅈㅈ

N = int(input())

if N == 1:
    print(0)
elif N == 2:
    print(1)
else:
    print(2 ** (N - 2) % 1000000007)
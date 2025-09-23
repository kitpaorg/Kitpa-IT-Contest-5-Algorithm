import sys
input = sys.stdin.readline

# Subtask 1
N, M = map(int, input().split())
L = list(map(int, input().split()))
k = max(L)
for x in L:
    if x == k: print(0, end = ' ')
    else: print(1, end = ' ')
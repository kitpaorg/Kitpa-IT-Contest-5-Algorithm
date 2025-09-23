import sys
input = sys.stdin.readline

N, M = map(int, input().split())
L = [list(map(int, input().split())) for _ in range(N)]
max_score = [0] * N
for i in range(N):
    for j in range(M):
        max_score[i] = max(max_score[i], L[i][j])
ans = [0] * M
for i in range(N):
    for j in range(M):
        if L[i][j] != max_score[i]:
            ans[j] += 1
print(*ans)
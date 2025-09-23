import sys
input = sys.stdin.readline
sys.setrecursionlimit(50000)

N, K = map(int, input().split())
S = [0] + list(map(int, input().split()))
G = [[] for _ in range(N + 1)]
for _ in range(N):
    a, b, w = map(int, input().split())
    G[a].append((b, w))
    G[b].append((a, w))
ans = 0
visited = [False] * (N + 1)
def dfs(v):
    global ans
    visited[v] = True
    for u, w in G[v]:
        if not visited[u]:
            dfs(u)
            ans += 2 * w * ((S[u] - 1) // K + 1)
            S[v] += S[u]
dfs(0)
print(ans)
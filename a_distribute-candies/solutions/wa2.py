n = int(input())
L = list(map(int, input().split()))
L.sort()
ans = "Yes"
for i in range(1, 2*n-2):
    if L[i] == L[i+1] == L[i+2]:
        ans = "No"
print(ans)

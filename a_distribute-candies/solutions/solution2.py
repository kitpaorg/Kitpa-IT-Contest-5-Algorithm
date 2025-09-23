n = int(input())
L = list(map(int, input().split()))
count = [0] * (2*n+1)
for k in L: count[k] += 1
for i in range(2*n+1):
    if count[i] > 2:
        print("No")
        exit()
print("Yes")
n=int(input())
a=sorted(map(int,input().split()))
if any(a[i-2]==a[i] for i in range(2,2*n)):
  print("No")
else:
  print("Yes")
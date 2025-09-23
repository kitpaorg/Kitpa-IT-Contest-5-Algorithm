#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(int argc,char*argv[])
{
  registerGen(argc,argv,1);
  int n=atoi(argv[1]);
  cout<<n<<"\n";
  int B=rnd.next((int)sqrt(n)/2,(int)sqrt(n)*2);
  B=clamp(B,1,n-1);
  for(int i=1;i<n;i++)
  {
    int t=(i-1)/B+1;
    cout<<t<<" "<<i+1<<"\n";
  }
}
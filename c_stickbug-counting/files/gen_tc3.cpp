#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(int argc,char*argv[])
{
  registerGen(argc,argv,1);
  int n=atoi(argv[1]);
  cout<<n<<"\n";
  for(int i=1;i<n;i++)
  {
    int t;
    if(rnd.next(2))t=1;
    else t=i;
    cout<<t<<" "<<i+1<<"\n";
  }
}
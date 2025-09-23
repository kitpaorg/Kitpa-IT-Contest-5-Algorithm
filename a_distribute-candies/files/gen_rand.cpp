#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(int argc,char*argv[])
{
  registerGen(argc,argv,1);
  int n=atoi(argv[1]);
  map<int,int>cnt;
  cout<<n<<"\n";
  vector<int>res(2*n);
  for(int&i:res)
  {
    i=rnd.next(1,2*n);
    cnt[i]++;
  }
  println(res);
}

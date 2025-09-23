#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(int argc,char*argv[])
{
  registerGen(argc,argv,1);
  int q=atoi(argv[1]),sumk=atoi(argv[2]);
  cout<<q<<"\n";
  for(int k:rnd.partition(q,sumk))
  {
    cout<<rnd.next(2)<<" "<<k<<"\n";
  }
}
#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(int argc,char*argv[])
{
  registerValidation(argc,argv);
  int subtask=atoi(validator.group().c_str());
  int n=inf.readInt(1,100'000,"n");
  inf.readEoln();
  auto a=inf.readInts(2*n,1,2*n,"ai");
  inf.readEoln();
  if(subtask==1)ensure(n<=100);
  if(subtask==2)ensure(n<=3000);
  inf.readEof();
}

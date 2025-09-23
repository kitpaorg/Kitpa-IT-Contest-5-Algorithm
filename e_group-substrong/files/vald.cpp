#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(int argc,char*argv[])
{
  registerValidation(argc,argv);
  int q=inf.readInt(1,200'000,"q");
  int subtask=atoi(validator.group().c_str());
  inf.readEoln();
  ll tot=0;
  for(int i=0;i<q;i++)
  {
    inf.readInt(0,1,"ci");
    inf.readSpace();
    tot+=inf.readInt(1,1'000'000'000,"ki");
    inf.readEoln();
  }
  ensure(tot<=1'000'000'000);
  if(subtask==1)ensure(tot<=100);
  if(subtask==2)ensure(tot<=3000);
  if(subtask==3)ensure(tot<=1'000'000);
  inf.readEof();
}
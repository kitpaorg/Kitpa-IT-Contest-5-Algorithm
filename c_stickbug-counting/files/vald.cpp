#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(int argc,char*argv[])
{
  registerValidation(argc,argv);
  int n=inf.readInt(2,300'000,"n");
  inf.readEoln();
  int subtask=atoi(validator.group().c_str());
  vector<int>dsu(n);
  for(int i=0;i<n;i++)dsu[i]=i;
  auto find=[&](int i)
  {
    while(dsu[i]!=i)i=dsu[i]=dsu[dsu[i]];
    return i;
  };
  __int128 count=0;
  vector<__int128>deg(n);
  vector<pair<int,int>>edges;
  for(int i=1;i<n;i++)
  {
    int u=inf.readInt(1,n,"ui");
    inf.readSpace();
    int v=inf.readInt(1,n,"vi");
    inf.readEoln();
    ensure(u!=v);
    if(subtask==3)
    {
      ensure(u==1||u==i);
      ensure(v==i+1);
    }
    u--;v--;
    edges.emplace_back(u,v);
    deg[u]++;deg[v]++;
    u=find(u);v=find(v);
    ensure(u!=v);
    dsu[u]=v;
  }
  for(auto[u,v]:edges)
  {
    count+=(deg[u]-1)*(deg[u]-2)*(deg[v]-1)*(deg[v]-2)/4;
  }
  ensure(count<=1'000'000'000'000'000'000LL);
  if(subtask==1)ensure(n<=300);
  if(subtask==2)ensure(n<=3000);
  inf.readEof();
}
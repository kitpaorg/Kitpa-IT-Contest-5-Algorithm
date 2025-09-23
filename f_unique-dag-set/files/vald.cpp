#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(int argc,char*argv[])
{
  registerValidation(argc,argv);
  int tc=inf.readInt(1,1000,"t");
  int subtask=atoi(validator.group().c_str());
  inf.readEoln();
  ll sumn=0,summ=0;
  for(int t=1;t<=tc;t++)
  {
    setTestCase(t);
    int n=inf.readInt(1,300'000,"n");
    inf.readSpace();
    int m=inf.readInt(1,500'000,"m");
    inf.readEoln();
    vector<int>ideg(n);
    vector<vector<int>>adj(n);
    set<pair<int,int>>S;
    for(int i=0;i<m;i++)
    {
      int u=inf.readInt(1,n,"ik");
      inf.readSpace();
      int v=inf.readInt(1,n,"jk");
      inf.readEoln();
      S.emplace(u,v);
      ensure(u!=v);
      u--;v--;
      adj[u].push_back(v);
      ideg[v]++;
    }
    ensuref(S.size()==m,"all info distinct");
    queue<int>Q;
    for(int i=0;i<n;i++)
    {
      if(!ideg[i])Q.push(i);
    }
    int cnt=0;
    while(!Q.empty())
    {
      int v=Q.front();
      Q.pop();
      cnt++;
      for(int w:adj[v])
      {
        ideg[w]--;
        if(ideg[w]==0)Q.push(w);
      }
    }
    ensuref(cnt==n,"graph is DAG");
    sumn+=n;summ+=m;
  }
  if(subtask==1)
  {
    ensure(sumn<=10);
  }
  if(subtask==2)
  {
    ensure(sumn<=20);
  }
  if(subtask==3)
  {
    ensure(sumn<=200);
  }
  if(subtask==4)
  {
    ensure(sumn<=2000);
    ensure(sumn<=20000);
  }
  ensure(sumn<=300'000);
  ensure(summ<=500'000);
  inf.readEof();
}

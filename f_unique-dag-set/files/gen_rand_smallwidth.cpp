#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(int argc,char*argv[])
{
  registerGen(argc,argv,1);
  int tc=atoi(argv[1]);
  int sumn=atoi(argv[2]);
  int summ=atoi(argv[3]);
  auto ns=rnd.partition(tc,sumn,2);
  auto ms=rnd.partition(tc,summ);
  cout<<tc<<"\n";
  for(int i=0;i<tc;i++)
  {
    int n=ns[i],m=ms[i];
    vector<int>perm(n);
    for(int i=0;i<n;i++)perm[i]=i+1;
    shuffle(begin(perm),end(perm));
    set<pair<int,int>>S;
    for(int i=0;i<m;i++)
    {
      int u=rnd.next(0,n-2);
      int v=rnd.next(u+1,min(n-1,u+10));
      S.emplace(u,v);
    }
    vector<pair<int,int>>V(begin(S),end(S));
    shuffle(begin(V),end(V));
    m=size(S);
    cout<<n<<" "<<m<<"\n";
    for(auto[u,v]:V)cout<<perm[u]<<" "<<perm[v]<<"\n";
  }
}

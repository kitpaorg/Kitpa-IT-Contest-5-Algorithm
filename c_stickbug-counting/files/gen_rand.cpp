#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(int argc,char*argv[])
{
  registerGen(argc,argv,1);
  int n=atoi(argv[1]);
  cout<<n<<"\n";
  vector<pair<int,int>>edges;
  vector<int>vis(n);
  vis[0]=1;int p=0,cnt=1;
  while(cnt<n)
  {
    int r=rnd.next(n);
    if(!vis[r])
    {
      vis[r]=1;
      edges.emplace_back(p,r);
      cnt++;
    }
    p=r;
  }
  shuffle(begin(edges),end(edges));
  for(auto[u,v]:edges)
  {
    if(rnd.next(2))swap(u,v);
    cout<<u+1<<" "<<v+1<<"\n";
  }
}
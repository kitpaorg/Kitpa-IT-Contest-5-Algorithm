#include<bits/stdc++.h>
#include<tr2/dynamic_bitset>
using namespace std;

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m;cin>>n>>m;
    
    vector<tr2::dynamic_bitset<>>rch(n);
    for(int i=0;i<n;i++)
    {
      rch[i].resize(n);
      rch[i][i]=true;
    }
    vector<int>ideg(n);
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++)
    {
      int u,v;cin>>u>>v;
      u--;v--;
      adj[u].push_back(v);
      ideg[v]++;
    }
    queue<int>Q;
    for(int i=0;i<n;i++)
    {
      if(!ideg[i])Q.push(i);
    }
    while(!Q.empty())
    {
      int v=Q.front();
      Q.pop();
      for(int w:adj[v])
      {
        ideg[w]--;rch[w]|=rch[v];
        if(ideg[w]==0)Q.push(w);
      }
    }
    vector<int>vec(n+1);
    for(int i=0;i<n;i++)vec[rch[i].count()]++;
    for(int i=0;i<n;i++)vec[i+1]+=vec[i];
    for(int i=1;i<=n;i++)
    {
      cout<<(vec[i]<=i);
    }
    cout<<"\n";
  }
}
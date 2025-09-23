#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  ll n,k;cin>>n>>k;
  vector<ll>S(n+1);
  for(int i=1;i<=n;i++)cin>>S[i];
  vector<vector<pair<ll,ll>>>G(n+1);
  for(int i=0;i<n;i++)
  {
    ll u,v,w;cin>>u>>v>>w;
    G[u].emplace_back(v,w);
    G[v].emplace_back(u,w);
  }
  ll ans=0;
  auto dfs=[&](auto dfs,ll v,ll p=-1)->void
  {
    for(auto[u,w]:G[v])if(u!=p)
    {
      dfs(dfs,u,v);
      ans+=2*w*((S[u]+k-1)/k);
      S[v]+=S[u];
    }
  };
  dfs(dfs,0);
  cout<<ans<<"\n";
}
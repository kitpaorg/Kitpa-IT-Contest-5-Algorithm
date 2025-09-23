#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  ll n;cin>>n;
  vector<pair<int,int>>edges(n-1);
  vector<ll>deg(n);
  for(auto&[u,v]:edges)
  {
    cin>>u>>v;
    u--;v--;
    deg[u]++;deg[v]++;
  }
  ll ans=0;
  for(auto&[u,v]:edges)
  {
    ans+=(deg[u]-1)*(deg[u]-2)*(deg[v]-1)*(deg[v]-2)/4;
  }
  cout<<ans<<"\n";
}
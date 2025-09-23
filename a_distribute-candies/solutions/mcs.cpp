#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  ll n;cin>>n;
  vector<ll>cnt(2*n+1);
  bool ok=1;
  for(int i=0;i<2*n;i++)
  {
    ll x;cin>>x;
    cnt[x]++;
    if(cnt[x]>2)ok=0;
  }
  if(ok)cout<<"Yes\n";
  else cout<<"No\n";
}
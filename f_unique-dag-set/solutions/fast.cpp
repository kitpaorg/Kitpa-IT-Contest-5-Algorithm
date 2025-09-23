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
    vector<int>leaf(n),ideg(n);
    vector<vector<int>>adj(n);
    vector<vector<int>>rev(n);
    for(int i=0;i<m;i++)
    {
      int u,v;cin>>u>>v;
      u--;v--;
      adj[u].push_back(v);
      rev[v].push_back(u);
      ideg[v]++;
    }
    queue<int>Q;
    for(int i=0;i<n;i++)
    {
      if(!ideg[i])
      {
        Q.push(i);
      }
    }
    string ans(n,'0');
    int lcnt=0;
    for(int i=0;i<n;i++)
    {
      int v=Q.front();
      Q.pop();
      bool B=Q.empty();
      leaf[v]=1;lcnt++;
      for(int p:rev[v])
      {
        if(leaf[p])
        {
          leaf[p]=0;
          lcnt--;
        }
      }
      if(B)ans[i]='1';
      for(int w:adj[v])
      {
        ideg[w]--;
        if(ideg[w]==0)
        {
          Q.push(w);
          if(B)
          {
            int cc=0;
            for(int p:rev[w])
            {
              if(leaf[p])cc++;
            }
            if(cc<lcnt)ans[i]='0';
          }
        }
      }
    }
    cout<<ans<<"\n";
  }
}
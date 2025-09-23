#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct pt
{
	ll x,y;
	bool operator<(const pt&o) const
	{
		if(x!=o.x)return x<o.x;
		return y<o.y;
	}
};
struct MonoContainer:set<pt,less<pt>>
{
	ll area;
	void del(iterator it)
	{
		--it;
		auto[xb,yb]=*it;
		++it;
		auto[x,y]=*it;
		++it;
		auto[xa,ya]=*it;
		--it;
		area-=(y-ya)*(x-xb);
		erase(it);
	}
	void add(iterator it)
	{
		--it;
		auto[xb,yb]=*it;
		++it;
		auto[x,y]=*it;
		++it;
		auto[xa,ya]=*it;
		--it;
		area+=(y-ya)*(x-xb);
	}
	void add(ll x,ll y)
	{
		auto it=lower_bound(pt{x,y});
		if((*it).y>=y)return;
		it--;
		while((*it).y<=y)
		{
			auto tmp=it;
			--it;
			del(tmp);
		}
		auto [itt,bb]=insert(pt{x,y});
		add(itt);
	}
	void init()
	{
		area=0;
		insert(pt{0,1LL<<60});
		insert(pt{1LL<<60,0});
	}
};

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int q;cin>>q;
  ll ans=0;
  MonoContainer M01,M10;
  M01.init();M10.init();
  ll m0=0,m1=0;
  ll pcnt=0,prev=-1,cnt=0;
  while(q--)
  {
    ll a,b;cin>>a>>b;
    if(prev==-1)
    {
      if(a==0)m0=b;
      else m1=b;
      prev=a;cnt=b;
    }
    else if(prev==0)
    {
      if(a==0)
      {
        cnt+=b;
        m0=max(m0,cnt);
        M10.add(pcnt,cnt);
      }
      else
      {
        pcnt=cnt;prev=a;cnt=b;
        m1=max(m1,cnt);
        M01.add(pcnt,cnt);
      }
      
    }
    else
    {
      if(a==1)
      {
        cnt+=b;
        m1=max(m1,cnt);
        M01.add(pcnt,cnt);
      }
      else
      {
        pcnt=cnt;prev=a;cnt=b;
        m0=max(m0,cnt);
        M10.add(pcnt,cnt);
      }
    }
    //for(auto[x,y]:M10)cout<<"["<<x<<","<<y<<"] ";
    //cout<<endl;
    //for(auto[x,y]:M01)cout<<"["<<x<<","<<y<<"] ";
    //cout<<endl;
    cout<<m0+m1+M10.area+M01.area<<"\n";
  }
}
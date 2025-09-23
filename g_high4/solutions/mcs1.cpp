#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
#define X first
#define Y second
#define CNT_LOWER(v,n) (int)(lower_bound((v).begin(),(v).end(),(n))-(v).begin())
#define CNT_UPPER(v,n) (int)(upper_bound((v).begin(),(v).end(),(n))-(v).begin())
#define all(x) (x).begin(), (x).end()
 
// CNT_LOWER: number of element in v smaller than n
// CNT_UPPER: number of element in v smaller or same than n
 
#define LINE array<pii, 2>
// LINE: l[0] + kl[1]
 
pii operator + (pii l, pii r){return {l.X+r.X, l.Y+r.Y};};
pii operator - (pii l, pii r){return {l.X-r.X, l.Y-r.Y};};
ll operator * (pii l, pii r){return (ll)l.X*r.X + (ll)l.Y*r.Y;};
ll operator / (pii l, pii r){return (ll)l.X*r.Y - (ll)l.Y*r.X;};
 
const ll MXI = 0x3f3f3f3f0ll;
 
struct seg0{
    int n = 202020;
    ll tree[1010101], lazy[1010101];
    void update(int node, int st, int ed, int l, int r, ll val){
        F(node, st, ed);
        if(ed < l or r < st) return;
        if(l <= st and ed <= r){
            lazy[node] = val; F(node, st, ed);
            return;
        }
        update(node*2, st, (st+ed)/2, l, r, val);
        update(node*2+1, (st+ed)/2+1, ed, l, r, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    void update(int l, int r, ll val){
        update(1, 0, n-1, l, r, val);
    }
 
    ll query(int node, int st, int ed, int l, int r){
        F(node, st, ed);
        if(ed < l or r < st) return 0;
        if(l <= st and ed <= r) return tree[node];
        return query(node*2, st, (st+ed)/2, l, r) + query(node*2+1, (st+ed)/2+1, ed, l, r);
    }
    ll query(int l, int r){
        return query(1, 0, n-1, l, r);
    }
 
    void F(int node, int st, int ed){
        tree[node] += lazy[node] * (ed-st+1);
        if(st != ed){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
} S0;
 
struct seg1{
    int n = 202020;
    ll tree[1010101];
    pll lazy[1010101];
    void update(int node, int st, int ed, int l, int r, pll val){
        F(node, st, ed);
        if(ed < l or r < st) return;
        if(l <= st and ed <= r){
            lazy[node] = val; F(node, st, ed);
            return;
        }
        update(node*2, st, (st+ed)/2, l, r, val);
        update(node*2+1, (st+ed)/2+1, ed, l, r, val);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
    void update_max(int l, int r, ll val){
        update(1, 0, n-1, l, r, {val, 0});
    }
    void update_add(int l, int r, ll val){
        update(1, 0, n-1, l, r, {-MXI, val});
    }
 
    ll query(int node, int st, int ed, int l, int r){
        F(node, st, ed);
        if(ed < l or r < st) return -MXI;
        if(l <= st and ed <= r) return tree[node];
        return max(query(node*2, st, (st+ed)/2, l, r), query(node*2+1, (st+ed)/2+1, ed, l, r));
    }
    ll query(int l, int r){
        return query(1, 0, n-1, l, r);
    }
 
    void F(int node, int st, int ed){
        // max A, plus B, max C, plus D   equals
        // max A, max C-B, plus B, plus D
        tree[node] = max(tree[node], lazy[node].X) + lazy[node].Y;
        if(st != ed){
            lazy[node*2] = {max(lazy[node*2].X, lazy[node].X - lazy[node*2].Y), lazy[node].Y + lazy[node*2].Y};
            lazy[node*2+1] = {max(lazy[node*2+1].X, lazy[node].X - lazy[node*2+1].Y), lazy[node].Y + lazy[node*2+1].Y};
        }
        lazy[node] = {-MXI, 0};
    }
} S1;
 
int r, c, n, m, cntM[202020];
vector<pii> R_in[202020], R_out[202020], P_in[202020];
set<int> M;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> r >> c >> n >> m;
    for(int i=0; i<n; i++){
        int x, y, val; 
        cin >> x >> y >> val;
        P_in[x].push_back({y, val});
    }
    
    for(int i=0; i<m; i++){
        int x0, y0, x1, y1; 
        cin >> x0 >> y0 >> x1 >> y1;
        R_in[x0].push_back({y0,y1});
        R_out[x1+1].push_back({y0,y1});
        if(y0-1) P_in[x1+1].push_back({y0-1, 0});
    }
    P_in[1].push_back({1, 0});
 
    for(int i=1; i<=r; i++) sort(all(P_in[i]));
 
    M.insert(c+5); cntM[c+5]++;
    S1.update_add(0, c+5, -MXI);
    S1.update_max(1, 1, 0);
    for(int i=1; i<=r; i++){
        for(auto &[y0,y1]:R_in[i]){
            S0.update(y0, y1, 1);
            if(!cntM[y0]) M.insert(y0); cntM[y0]++;
            if(!cntM[y1]) M.insert(y1); cntM[y1]++;
            S1.update_add(y0, y1, -MXI);
        }
        for(auto &[y0,y1]:R_out[i]){
            S0.update(y0, y1, -1);
            cntM[y0]--; if(!cntM[y0]) M.erase(y0); 
            cntM[y1]--; if(!cntM[y1]) M.erase(y1);
        }
        for(auto &[y,val]:P_in[i]){
            if(S0.query(y, y) != 0){
                continue;
            }
            int up = *M.upper_bound(y);
            ll mx = max(S1.query(y-1,y-1), S1.query(y,y));
            S1.update_max(y, up-1, mx+val);
        }
    }
 
    ll ans = S1.query(c, c);
    ll A = (ans < 0 ? -1 : ans); assert(abs(A) <= 2'100'000'000ll);
    cout << (ans < 0 ? -1 : ans) << "\n";
    return 0;
}

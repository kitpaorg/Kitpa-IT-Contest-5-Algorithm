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

ll H[303030];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    srand(1557);
    for(int i=0; i<303030; i++) H[i] = ((ll)rand() << 32) ^ rand();

    int tt; cin >> tt;
    while(tt--){
        int n, m; cin >> n >> m;
        priority_queue<int, vector<int>, greater<int>> pq0;
        priority_queue<int> pq1;
        vector<vector<int>> v(n+1); 
        vector<int> deg0(n+1), deg1(n+1);
        for(int i=0; i<m; i++){
            int s, e; cin >> s >> e;
            v[s].push_back(e); deg0[e]++; deg1[e]++;
        }
        for(int i=1; i<=n; i++){
            if(!deg0[i]){
                pq0.push(i); pq1.push(i);
            }
        }
        string ans;
        ll h0 = 0, h1 = 0;
        for(int k=0; k<n; k++){
            int i0 = pq0.top(); pq0.pop();
            h0 ^= H[i0];
            for(int i:v[i0]){
                deg0[i]--;
                if(!deg0[i]) pq0.push(i);
            }
            int i1 = pq1.top(); pq1.pop();
            h1 ^= H[i1];
            for(int i:v[i1]){
                deg1[i]--;
                if(!deg1[i]) pq1.push(i);
            }
            ans.push_back( h0 == h1 ? '1' : '0' );
        }
        cout << ans << "\n";
    }
    return 0;
}
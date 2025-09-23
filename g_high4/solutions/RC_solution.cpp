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

int r, c, n, m;

int obstacle[1010][1010]; // solution for r <= 1000, c <= 1000
ll mp[1010][1010];
const ll MXI = 0x3f3f3f3f3f3f3f3fll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> r >> c >> n >> m;
    for(int i=0; i<n; i++){
        int x, y, val; 
        cin >> x >> y >> val;
        mp[x][y] = val;
    }
    for(int i=0; i<m; i++){
        int x0, y0, x1, y1; 
        cin >> x0 >> y0 >> x1 >> y1;
        obstacle[x0][y0] += 1;
        obstacle[x0][y1+1] -= 1;
        obstacle[x1+1][y0] -= 1;
        obstacle[x1+1][y1+1] += 1;
    }
    for(int i=0; i<1010; i++){
        for(int j=1; j<1010; j++){
            obstacle[i][j] += obstacle[i][j-1];
        }
    }
    for(int i=1; i<1010; i++){
        for(int j=0; j<1010; j++){
            obstacle[i][j] += obstacle[i-1][j];
        }
    }

    for(int i=0; i<1010; i++){
        for(int j=0; j<1010; j++){
            if(obstacle[i][j]) mp[i][j] = -MXI;
        }
    }
    for(int i=0; i<=r; i++) mp[i][0] = -MXI;
    for(int j=0; j<=c; j++) mp[0][j] = -MXI;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++) if(i>1 or j>1) {
            mp[i][j] = max(mp[i-1][j], mp[i][j-1]) + mp[i][j];
            mp[i][j] = max(mp[i][j], -MXI);
        }
    }

    if(mp[r][c] < 0) cout << "-1\n";
    else cout << mp[r][c] << "\n";
    return 0;
}
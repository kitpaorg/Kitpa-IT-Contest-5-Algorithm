#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
int main(int argc, char* argv[]) 
{
    registerGen(argc, argv, 1);
    int r = opt<int>("r");
    int c = opt<int>("c");
    int n = opt<int>("n");
    int m = opt<int>("m");
    
    int ntype = opt<int>("ntype");
    int mtype = opt<int>("mtype");
    
    if(ntype == 3){
        n = r + c - 2; assert(n <= 200'000);
    }
    
    cout << r << " " << c << " " << n << " " << m << "\n";
    set<pii> st;
    
    // RANDOM
    if(ntype == 0){
        for(int i=0; i<n; i++){
            while(true){
                int x = rnd.next(1, r), y = rnd.next(1, c)%4 + 1, val = rnd.next(1, 1000);
                if(st.find({x,y}) == st.end()){
                    cout << x << " " << y << " " << val << "\n";
                    st.insert({x,y});
                    break;
                }
            }
        }
    }
    
    // straight up
    else if(ntype == 1){
        assert(n <= min(r, c));
        for(int i=0; i<n; i++){
            int x = i + 1, y = i + 1, val = rnd.next(1, 1000);
            if(st.find({x,y}) == st.end()){
                cout << x << " " << y << " " << val << "\n";
                st.insert({x,y});
            }
        }
    }
    
    // straight down
    else if(ntype == 2){
        assert(n <= min(r, c));
        for(int i=0; i<n; i++){
            int x = i + 1, y = c - i, val = rnd.next(1, 1000);
            if(st.find({x,y}) == st.end()){
                cout << x << " " << y << " " << val << "\n";
                st.insert({x,y});
            }
        }
    }
    
    // straight down
    else if(ntype == 3){
        vector<int> v(n, 0);
        for(int i=0; i<r-1; i++) v[i] = 1;
        shuffle(v.begin(), v.end());
        int x = 1, y = 1;
        for(int i=0; i<n; i++){
            int val = rnd.next(1, 1000);
            if(st.find({x,y}) == st.end()){
                cout << x << " " << y << " " << val << "\n";
                st.insert({x,y});
            }
            if(v[i]) x++;
            else y++;
        }
    }
    
    // random
    if(mtype == 0){
        for(int i=0; i<m; i++){
            int x0 = rnd.next(1, r), y0 = rnd.next(1, c), x1 = rnd.next(x0, r), y1 = rnd.next(y0, c);
            if(pii(x0,y0) == pii(1,1) or pii(x1,y1) == pii(r,c)){
                i--; continue;
            }
            cout << x0 << " " << y0 << " " << x1 << " " << y1 << "\n";
        }
    }
    
    else if(mtype == 1){
        assert(ntype == 3);
        vector<array<int,4>> G;
        for(auto [x,y]:st){
            if(st.find({x+1,y}) == st.end() and x+1 <= r){
                int x0 = x+1, y1 = y;
                G.push_back({x0, rnd.next(1, y1), rnd.next(x0, r), y1});
                x0 = rnd.next(x0, r); y1 = rnd.next(1, y1);
                G.push_back({x0, rnd.next(1, y1), rnd.next(x0, r), y1});
            }
            if(st.find({x,y+1}) == st.end() and y+1 <= c){
                int x0 = x, y1 = y+1;
                G.push_back({rnd.next(1, x0), y1, x0, rnd.next(y1, c)});
                x0 = rnd.next(1, x0); y1 = rnd.next(y1, c);
                G.push_back({rnd.next(1, x0), y1, x0, rnd.next(y1, c)});
            }
        }
        for(int i=0; i<m; i++){
            int id = rnd.next(0, (int)G.size()-1);
            auto [x0, y0, x1, y1] = G[id];
            if(pii(x0,y0) == pii(1,1) or pii(x1,y1) == pii(r,c)){
                i--; continue;
            }
            cout << x0 << " " << y0 << " " << x1 << " " << y1 << "\n";
        }
    }
    return 0;
}

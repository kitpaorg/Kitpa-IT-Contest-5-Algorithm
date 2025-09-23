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
    
    cout << r << " " << c << " " << n << " " << m << "\n";
    set<pii> st;
    for(int i=0; i<n; i++){
        while(true){
            int x = rnd.next(1, r), y = rnd.next(1, c), val = rnd.next(1, 1000);
            if(st.find({x,y}) == st.end()){
                cout << x << " " << y << " " << val << "\n";
                st.insert({x,y});
                break;
            }
        }
    }
    for(int i=0; i<m; i++){
        int x0 = rnd.next(1, r), y0 = rnd.next(1, c), x1 = rnd.next(x0, r), y1 = rnd.next(y0, c);
        if(pii(x0,y0) == pii(1,1) or pii(x1,y1) == pii(r,c)){
            i--; continue;
        }
        cout << x0 << " " << y0 << " " << x1 << " " << y1 << "\n";
    }
    return 0;
}

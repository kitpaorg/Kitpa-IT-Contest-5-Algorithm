#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long ll;
using pii = pair<int,int>;
/*
subtask
1) r <= 100, c <= 100, m <= 100
2) r <= 1000, c <= 1000
3) m = 0
4) m = 1
5) no such restriction
*/

int main(int argc,char*argv[])
{
    registerValidation(argc,argv);
 
    string subtaskstr = validator.group();
	int subtask = atoi(subtaskstr.c_str());
 
    int r = inf.readInt(1, 200'000, "r");
    inf.readSpace();
    int c = inf.readInt(1, 200'000, "c");
    inf.readSpace();
    int n = inf.readInt(1, 200'000, "n");
    inf.readSpace();
    int m = inf.readInt(0, 200'000, "m");
    inf.readEoln();
    if(subtask == 1){
        inf.ensuref(1 <= r and r <= 100, "subtask 1 wrong validation on r");
        inf.ensuref(1 <= c and c <= 100, "subtask 1 wrong validation on c");
        inf.ensuref(0 <= m and m <= 100, "subtask 1 wrong validation on c");
    }
    else if(subtask == 2){
        inf.ensuref(1 <= r and r <= 1000, "subtask 2 wrong validation on r");
        inf.ensuref(1 <= c and c <= 1000, "subtask 2 wrong validation on c");
    }
    else if(subtask == 3){
        inf.ensuref(m == 0, "subtask 3 wrong validation on m");
    }
    else if(subtask == 4){
        inf.ensuref(m == 1, "subtask 4 wrong validation on m");
    }
    
    set<pii> chest_coordset;
    for (int i = 0; i < n; i++)
    {
        int x = inf.readInt(1, r, "x");
        inf.readSpace();
        int y = inf.readInt(1, c, "y");
        inf.readSpace();
        int value = inf.readInt(1, 1'000, "val");
        inf.readEoln();
        chest_coordset.insert(pii{x, y});
    }
    inf.ensuref((int)chest_coordset.size() == n, "chest coordinate collides");
    
    for (int i = 0; i < m; i++)
    {
        int x0 = inf.readInt(1, r, "x0");
        inf.readSpace();
        int y0 = inf.readInt(1, c, "y0");
        inf.readSpace();
        int x1 = inf.readInt(1, r, "x1");
        inf.readSpace();
        int y1 = inf.readInt(1, c, "y1");
        inf.readEoln();
        
        inf.ensuref(x0 <= x1 and y0 <= y1, "banned area error");
        inf.ensuref(pii(1,1) < pii(x0,y0) and pii(x1,y1) < pii(r, c), "banned area is invading starting(or ending) point");
    }
    inf.readEof();
    return 0;
}
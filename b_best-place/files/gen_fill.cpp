#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    int x = atoi(argv[3]);
    cout << N << ' ' << M << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << x;
            if (j != M-1) cout << ' ';
        }
        cout << '\n';
    }
}

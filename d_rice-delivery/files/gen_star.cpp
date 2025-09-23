#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);       // 마을 수
    int K = atoi(argv[2]);       // 최대 운반 가능 수
    int min_S = atoi(argv[3]);   // 최소 S (mode=0일 때만 사용)
    int mode = atoi(argv[4]);    // 0: 랜덤, 1: 전부 0, 2: 전부 100

    cout << N << ' ' << K << '\n';

    for (int i = 0; i < N; i++) {
        int S;
        if (mode == 1) S = 0;
        else if (mode == 2) S = 100;
        else S = rnd.next(min_S, 100);
        cout << S << (i + 1 == N ? '\n' : ' ');
    }

    vector<int> order(N);
    iota(order.begin(), order.end(), 1);
    shuffle(order.begin(), order.end());

    for (int v : order) {
        int T = rnd.next(1, 100);
        if (rnd.next(0, 1))
            cout << 0 << ' ' << v << ' ' << T << '\n';
        else
            cout << v << ' ' << 0 << ' ' << T << '\n';
    }
}

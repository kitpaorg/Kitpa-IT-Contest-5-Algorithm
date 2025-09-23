#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);
    int K = atoi(argv[2]);
    int min_S = atoi(argv[3]);

    cout << N << ' ' << K << '\n';

    for (int i = 0; i < N; i++) {
        int S = rnd.next(min_S, 100);
        cout << S << (i + 1 == N ? '\n' : ' ');
    }

    vector<int> order(N);
    iota(order.begin(), order.end(), 1);
    shuffle(order.begin(), order.end());

    cout << 0 << ' ' << order[0] << ' ' << rnd.next(1, 100) << '\n';
    for (int i = 1; i < N; i++) {
        cout << order[i - 1] << ' ' << order[i] << ' ' << rnd.next(1, 100) << '\n';
    }
}

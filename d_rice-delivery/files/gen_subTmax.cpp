#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);
    int K = atoi(argv[2]);
    cout << N << ' ' << K << '\n';

    for (int i = 0; i < N; i++) {
        int S = rnd.next(0, 100);
        cout << S << (i + 1 == N ? '\n' : ' ');
    }

    vector<pair<int,int>> edges;
    vector<int> visited(N+1);
    visited[0] = 1;
    int p = 0, cnt = 1;

    while (cnt <= N) {
        int r = rnd.next(N+1);
        if (!visited[r]) {
            visited[r] = 1;
            edges.emplace_back(p, r);
            cnt++;
        }
        p = r;
    }

    shuffle(edges.begin(), edges.end());
    for (auto [u, v] : edges) {
        cout << u << ' ' << v << " 100\n";
    }
}

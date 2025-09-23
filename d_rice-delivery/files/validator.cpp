#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int subtask = atoi(validator.group().c_str());
    int N = inf.readInt(1, 1'000, "N"); inf.readSpace();
    int K = inf.readInt(1, 100, "K"); inf.readEoln();
    int is_sub1 = 1; int is_sub2 = 1;
    vector<int> dsu(N+1);
    for (int i = 0; i <= N; i++) dsu[i] = i;
    auto find=[&](int i) {
        while(dsu[i]!=i)i=dsu[i]=dsu[dsu[i]];
        return i;
    };
    for (int i = 0; i < N; i++) {
        int S = inf.readInt(0, 100, "S");
        if (i != N-1) inf.readSpace();
        else inf.readEoln();
        if (S != K) is_sub2 = 0;
    }
    for (int i = 0; i < N; i++) {
        int A = inf.readInt(0, N, "A"); inf.readSpace();
        int B = inf.readInt(0, N, "B"); inf.readSpace();
        int T = inf.readInt(1, 100, "T"); inf.readEoln();
        if (T != 1) is_sub1 = 0;
        A = find(A); B = find(B);
        ensuref(A != B, "Graph is not a tree");
        dsu[A] = B;
    }
    if (subtask == 1) ensuref(is_sub1 == 1, "T must be 1 on subtask 1");
    if (subtask == 2) ensuref(is_sub2 == 1, "S must be K on subtask 2");
    inf.readEof();
}
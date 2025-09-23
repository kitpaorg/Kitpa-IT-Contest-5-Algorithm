#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(1, 1000, "N"); inf.readSpace();
    int M = inf.readInt(1, 1000, "M"); inf.readEoln();
    int subtask = atoi(validator.group().c_str());
    int can_sub3 = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int s = inf.readInt(1, 5, "s");
            if (s != 1 && s != 5) can_sub3 = 0;
            if (j == M - 1) inf.readEoln();
            else inf.readSpace();
        }
    }
    if (subtask == 1) ensuref(N == 1, "N must be 1 on subtask 1");
    if (subtask == 2) ensuref(N <= 200 && M <= 200, "N, M <= 200 on subtask 2");
    if (subtask == 3) ensuref(can_sub3 == 1, "Score = 1 or 5 on subtask 3");
    inf.readEof();
}
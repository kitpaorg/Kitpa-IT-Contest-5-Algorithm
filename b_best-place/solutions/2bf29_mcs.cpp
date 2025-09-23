#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> L(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> L[i][j];
        }
    }

    std::vector<int> max_score(N, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            max_score[i] = std::max(max_score[i], L[i][j]);
        }
    }

    std::vector<int> ans(M, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (L[i][j] != max_score[i]) {
                ans[j] += 1;
            }
        }
    }

    for (int j = 0; j < M; ++j) {
        std::cout << ans[j] << (j == M - 1 ? '\n' : ' ');
    }

    return 0;
}


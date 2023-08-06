#include <iostream>
#include <vector>
#include <algorithm>

struct Window {
    int rows;
    int cols;
};


void slidingWindow(const std::vector<std::vector<int>>& matrix, const Window& window) {
    int M = matrix.size();
    int N = matrix[0].size();
    int m = window.rows;
    int n = window.cols;

    std::vector<int> histogram(256, 0); 

    for (int i = 0; i <= M - m; ++i) {
        for (int j = 0; j <= N - n; ++j) {
            int maxVal = 0;
            
            for (int x = 0; x < m; ++x) {
                for (int y = 0; y < n; ++y) {
                    maxVal = std::max(maxVal, matrix[i + x][j + y]);
                }
            }

            histogram[maxVal]++;
        }
    }

    for (int i = 0; i < 256; ++i) {
        if (histogram[i] > 0) {
            std::cout << i << " " << histogram[i] << std::endl;
        }
    }
}

int main() {
    int M, N, m, n;
    std::cin >> M >> N >> m >> n;

    std::vector<std::vector<int>> matrix(M, std::vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    Window window = { m, n };
    slidingWindow(matrix, window);

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int kadane(vector<int>& arr) {
    int maxSum = INT_MIN, sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (maxSum < sum) {
            maxSum = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxSum;
}

int maxSubMatrix(vector<vector<int>>& matrix) {
    int N = matrix.size();
    int maxRectangle = INT_MIN;
    for (int left = 0; left < N; left++) {
        vector<int> tmp(N, 0);
        for (int right = left; right < N; right++) {
            for (int i = 0; i < N; i++) {
                tmp[i] += matrix[i][right];
            }
            maxRectangle = max(maxRectangle, kadane(tmp));
        }
    }
    return maxRectangle;
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << maxSubMatrix(matrix) << endl;
    return 0;
}

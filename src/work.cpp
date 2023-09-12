#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> matrix(n, vector<int>(n, 1));

    for (int i = 0; i < n && k > 0; i++) {
        for (int j = i; j < n && k > 0; j++) {
            if (matrix[i][j] == 1 && k >= 2) {
                matrix[i][j] = 0;
                matrix[j][i] = 0;
                if (i == j) k--;
                else{
                    k -= 2;
                } 
            }else{
                if(i == j)
                    matrix[i][j] = 0;
                else{
                    matrix[i + 1][i + 1] = 0;
                }
                k--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j];
            if (j != n - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}

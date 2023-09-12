#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long int n, k;
    cin >> n >> k;

    vector<long int> beauty_values(n);
    for (long int i = 0; i < n; ++i) {
        cin >> beauty_values[i];
    }

    sort(beauty_values.rbegin(), beauty_values.rend());  // 从大到小排序

    long int happiness = 0;
    long int count = 0;

    for (long int i = 0; i < n; ++i) {
        if (beauty_values[i] > 0) {
            happiness += beauty_values[i];
            count++;
        } else if (i + 2 < n && beauty_values[i] + beauty_values[i + 1] + beauty_values[i + 2] + k > 0) {
            happiness += beauty_values[i] + beauty_values[i + 1] + beauty_values[i + 2] + k;
            count += 3;
            i += 2;
        }
    }

    happiness += (count / 3) * k;

    cout << happiness << endl;

    return 0;
}

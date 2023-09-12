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
    int record = 0;

    for (long int i = 0; i < n; ++i) {
        if (beauty_values[i] > 0) {
            record++;
            happiness += beauty_values[i];
            count++;
            if(record == 3){
                record = 0;
                happiness += k;
            }
        } else if(record != 0){
            if(record == 1){
                if(i + 1 < n && beauty_values[i] + beauty_values[i + 1] + k > 0){
                    happiness += beauty_values[i] + beauty_values[i + 1] + k;
                    i += 1;
                }
            }else if(record == 2){
                if(beauty_values[i] + k > 0){
                    happiness += beauty_values[i] + k;
                }
            }
            record = 0;
        }else if (i + 2 < n && beauty_values[i] + beauty_values[i + 1] + beauty_values[i + 2] + k > 0) {
            happiness += beauty_values[i] + beauty_values[i + 1] + beauty_values[i + 2] + k;
            count += 3;
            i += 2;
        }
    }

    // happiness += (count / 3) * k;

    cout << happiness << endl;

    return 0;
}

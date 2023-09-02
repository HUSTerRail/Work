#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> red(N), white(N), yellow(N), pink(N);
    for(int i = 0; i < N; ++i) {
        cin >> red[i] >> white[i] >> yellow[i] >> pink[i];
    }
    unordered_map<int, int> colorSum;
    for(int r : red) {
        for(int w : white) {
            ++colorSum[r + w];
        }
    }
    int count = 0;
    for(int y : yellow) {
        for(int p : pink) {
            int need = 1000 - (y + p);
            if(colorSum.find(need) != colorSum.end()) {
                count += colorSum[need];
            }
        }
    }  
    cout << count << endl;
    return 0;
}

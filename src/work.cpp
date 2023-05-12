#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s, t;
    cin >> n >> s;
    int l = 0, r = n - 1; 
    while (l <= r) { 
        bool left = false;
        for (int i = 0; l + i <= r; i++) { 
            if (s[l + i] < s[r - i]) {
                left = true;
                break;
            } else if (s[l + i] > s[r - i]) {
                left = false;
                break;
            }
        }
        if (left) {
            t += s[l];
            l++;
        } else {
            t += s[r];
            r--;
        }
    }
    cout << t << endl;
    return 0;
}

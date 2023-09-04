#include <iostream>
#include <string>
using namespace std;

string maximizeNumber(string num) {
    int n = num.length();
    // 最后一位字符肯定不会交换，所以初始化为最后一个字符
    char maxChar = num[n-1];
    // 记录从后向前看每个位置的最大字符
    string maxRight(n, '0');
    maxRight[n-1] = num[n-1];
    
    for (int i = n-2; i >= 0; --i) {
        if (num[i] > maxChar) {
            maxChar = num[i];
        }
        maxRight[i] = maxChar;
    }
    
    for (int i = 0; i < n - 1; ++i) {
        if (num[i] < maxRight[i]) {
            // 找到第一个比num[i]大的字符，并交换
            for (int j = n-1; j > i; --j) {
                if (num[j] == maxRight[i]) {
                    swap(num[i], num[j]);
                    return num;
                }
            }
        }
    }
    return num;
}

int main() {
    string num;
    cin >> num;
    cout << maximizeNumber(num) << endl;
    return 0;
}

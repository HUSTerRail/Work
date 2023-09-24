#include <bits/stdc++.h>

using namespace std;

// 检查字符串是否为回文
bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        ++start;
        --end;
    }
    return true;
}

// 回溯函数
void backtrack(vector<vector<string>>& res, vector<string>& path, const string& s, int start) {
    // 如果开始位置达到字符串的长度，说明找到了一种分割方案
    if (start == s.size()) {
        res.push_back(path);
        return;
    }

    for (int end = start; end < s.size(); ++end) {
        // 如果从start到end是回文，则继续寻找下一组分割方案
        if (isPalindrome(s, start, end)) {
            path.push_back(s.substr(start, end - start + 1));
            backtrack(res, path, s, end + 1);
            path.pop_back();
        }
    }
}

int main() {
    string s;
    cin >> s;

    vector<vector<string>> res;
    vector<string> path;
    backtrack(res, path, s, 0);

    // 输出所有可能的分割方案
    for (const auto& vec : res) {
        for (const auto& str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int getMinModification(const string& s) {
    stack<char> st;
    int modificationCount = 0;

    for (char c : s) {
        if (c == '(' || c == '<' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                modificationCount++;
            } else {
                char top = st.top();
                st.pop();
                if ((top == '(' && c != ')') ||
                    (top == '<' && c != '>') ||
                    (top == '[' && c != ']') ||
                    (top == '{' && c != '}')) {
                    modificationCount++;
                }
            }
        }
    }

    return modificationCount + st.size(); // 添加剩余左括号的修改次数
}

int main() {
    string s;
    cin >> s;

    int minModification = getMinModification(s);
    cout << minModification << endl;

    return 0;
}

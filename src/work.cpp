#include <iostream>
#include <stack>
#include <string>

using namespace std;

int getMinModification(const string& s) {
    int modificationCount = 0;
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '<' || c == '[' || c == '{') {
            st.push(c); // 将左括号入栈
        } else {
            if (!st.empty()) { // 如果栈不为空
                char top = st.top(); // 获取栈顶元素
                st.pop(); // 弹出栈顶元素
                if ((top == '(' && c != ')') || (top == '<' && c != '>') ||
                    (top == '[' && c != ']') || (top == '{' && c != '}')) {
                    modificationCount++; // 如果当前字符与栈顶元素不匹配，则需要进行修改
                }
            } else {
                // 如果没有对应的左括号，需要添加一个左括号
                modificationCount++;
            }
        }
    }

    return modificationCount + st.size()/2; // 添加剩余的左括号数量
}

int main() {
    string s;
    cin >> s;

    int minModification = getMinModification(s);
    cout << minModification << endl;

    return 0;
}

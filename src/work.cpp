#include<bits/stdc++.h>
using namespace std;

int getMinModification(const string& s) {
    int modificationCount = 0;
    int fankuohao = 0;
    stack<char> st;

    // for (char c : s) {
    for(int i = 0; i<s.length(); i++){
        char c = s[i];
    
        if (c == '(' || c == '<' || c == '[' || c == '{') {
            st.push(c); 
        } else {
            if (!st.empty()) { 
                char top = st.top(); 
                st.pop(); // 弹出栈顶元素
                if ((top == '(' && c != ')') || (top == '<' && c != '>') ||
                    (top == '[' && c != ']') || (top == '{' && c != '}')) {
                    // cout<<"didi"<<endl;
                    modificationCount++; 
                }
            } else {
               
                fankuohao++;
            
            }
        }
    }

    return modificationCount + st.size()/2 +fankuohao/2 +fankuohao%2 +  st.size()%2; // 添加剩余的左括号数量
}

int main() {
    string s;
    cin >> s;

    int minModification = getMinModification(s);
    cout << minModification << endl;

    return 0;
}

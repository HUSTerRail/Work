#include <iostream>
#include <string>
#include <sstream>

using namespace std;

double str_to_double(string str)
{
    double result;
    stringstream ss(str); // 使用stringstream将字符串转换为double型数据
    ss >> result;
    return result;
}

int main()
{
    string str;
    cin >> str;
    double num = str_to_double(str);
    cout << num << endl;
    return 0;
}

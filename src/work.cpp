#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int len;
    string str;
    cin >> len >> str;

    int pos = str.find('+');
    if (pos == string::npos) {
        // 如果字符串中没有加号，说明表达式无效
        cout << "Invalid expression" << endl;
        return 0;
    }

    string left_str = str.substr(0, pos);
    string right_str = str.substr(pos + 1);

    double left_val, right_val, result;
    char op = '+';

    // 根据字符串中是否包含特殊字符，来选择不同的计算方式
    if (left_str.find('!') == string::npos && left_str.find('@') == string::npos && left_str.find('#') == string::npos
        && right_str.find('!') == string::npos && right_str.find('@') == string::npos && right_str.find('#') == string::npos) {
        // 如果字符串中不包含特殊字符，直接进行数值计算
        left_val = stod(left_str);
        right_val = stod(right_str);
        result = left_val + right_val;
    } else {
        // 如果字符串中包含特殊字符，按照题目要求进行计算
        double left_num = stod(left_str);
        double right_num = stod(right_str);

        if (left_str == "!") {
            if (right_str == "!") {
                result = 0;
            } else if (right_str == "@") {
                result = 13;
            } else if (right_str == "#") {
                result = 4;
            }
        } else if (left_str == "@") {
            if (right_str == "@") {
                result = 7;
            } else if (right_str == "#") {
                result = 20;
            }
        } else if (left_str == "#") {
            if (right_str == "#") {
                result = 5;
            }
        } else if (right_str == "!") {
            if (left_str == "@") {
                result = 13;
            } else if (left_str == "#") {
                result = 4;
            }
        } else if (right_str == "@") {
            if (left_str == "#") {
                result = 20;
            }
        }

        if (op == '+') {
            result += left_num + right_num;
        }
    }

    // 对结果进行四舍五入，并输出
    int int_part = (int)result;
    double decimal_part = result - int_part;
    decimal_part = round(decimal_part * 100) / 100; // 保留两位小数，四舍五入
    if (decimal_part == 0) {
        printf("%d\n", int_part);
    } else {
        printf("%.2f\n", result);
    }

    return 0;
}

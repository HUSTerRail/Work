#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

string add(string num1, string num2) {
    double x, y;
    stringstream ss1(num1), ss2(num2);
    ss1 >> x;
    ss2 >> y;
    double sum = x + y;
    stringstream ss;
    ss << fixed << setprecision(2) << sum;
    return ss.str();
}

string sub(string num1, string num2) {
    double x, y;
    stringstream ss1(num1), ss2(num2);
    ss1 >> x;
    ss2 >> y;
    double diff = x - y;
    stringstream ss;
    ss << fixed << setprecision(2) << diff;
    return ss.str();
}

int main() {
    string num1, num2, op;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "Enter an operator (+ or -): ";
    cin >> op;

    string result;
    if (op == "+") {
        result = add(num1, num2);
    } else if (op == "-") {
        result = sub(num1, num2);
    } else {
        cerr << "Invalid operator: " << op << endl;
        return 1;
    }

    cout << "Result: " << result << endl;
    return 0;
}

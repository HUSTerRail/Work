#include <bits/stdc++.h>
using namespace std;

string generate_contract(string product, int year, int month) {
    stringstream ss; 
    ss << product << (year % 100);
    if (month < 10) ss << '0';
    ss << month;
    return ss.str();
}

int main() {
    string input;
    getline(cin, input);
    set<string> s_set;

    stringstream ss(input);
    string m_str, n_str, yymm_str, x_str;
    getline(ss, m_str, ',');
    getline(ss, n_str, ',');
    getline(ss, yymm_str, ',');
    getline(ss, x_str, ',');

    int m = stoi(m_str);
    int n = stoi(n_str);
    int yy = stoi(yymm_str.substr(0, 2));
    int mm = stoi(yymm_str.substr(2, 2));
    int x = stoi(x_str);

    vector<int> quarter_months = {3, 6, 9, 12};

    for (int i = 0; i < x; ++i) {
        vector<string> contracts;

        // Calculate contracts for near months
        for (int j = 0; j < m; ++j) {
            int future_mm = mm + i + j;
            int future_yy = yy + (future_mm - 1) / 12;
            future_mm = (future_mm - 1) % 12 + 1;
            string temp = generate_contract("IZ", future_yy, future_mm);
            if(s_set.find(temp) == s_set.end()){
                contracts.push_back(temp);
                s_set.insert(temp);
            }
        }

        // Calculate contracts for quarter months
        for (int j = 0; j < quarter_months.size(); ++j) {
            // int future_yy = yy + (mm + i - 1) / 12 + j / 4;
            // int quarter_index = (j + quarter_months.size() + (mm + i - 1) % 12 / 3) % 4;
            // int future_mm = quarter_months[quarter_index];
            int future_yy,future_mm;
            if(i + mm == quarter_months[j]){
                future_yy = yy;
                future_mm = quarter_months[j];
            }else if(i + mm < quarter_months[j] && quarter_months[j] - i - mm <= 8){
                future_yy = yy;
                future_mm = quarter_months[j];
            }else{
                if(12 - i - mm + quarter_months[j] < 8){
                future_yy = yy + 1;
                future_mm = quarter_months[j];
                }
            }

            string temp = generate_contract("IZ", future_yy, future_mm);
            if(s_set.find(temp) == s_set.end()){
                contracts.push_back(temp);
                s_set.insert(temp);
            }
        }

        // Output
        if (contracts.empty()) {
            cout << "-" << endl;
        } else {
            for (size_t j = 0; j < contracts.size(); ++j) {
                cout << contracts[j];
                if (j < contracts.size() - 1) cout << ',';
            }
            cout << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;


int convertToMinutes(const string& timeStr) {
    int hours, minutes;
    char delimiter;
    stringstream ss(timeStr);
    ss >> hours >> delimiter >> minutes;
    return hours * 60 + minutes;
}


string convertToTime(int minutes) {
    int hours = minutes / 60;
    int mins = minutes % 60;
    stringstream ss;
    ss << hours / 10 << hours % 10 << ":" << mins / 10 << mins % 10;
    return ss.str();
}


string getNextAlarmTime(const string& currentTime, const vector<string>& alarmTimes) {
    int currentMinutes = convertToMinutes(currentTime);
    int nextAlarmMinutes = 24 * 60; // 初始化为一个较大的值
    for (const auto& alarmTime : alarmTimes) {
        int alarmMinutes = convertToMinutes(alarmTime);
        if (alarmMinutes > currentMinutes && alarmMinutes < nextAlarmMinutes) {
            nextAlarmMinutes = alarmMinutes;
        }
    }
    return convertToTime(nextAlarmMinutes);
}

int main() {
    string currentTime;
    cin >> currentTime;
    
    int n;
    cin >> n;
    
    vector<string> alarmTimes(n);
    for (int i = 0; i < n; i++) {
        cin >> alarmTimes[i];
    }
    
    string nextAlarmTime = getNextAlarmTime(currentTime, alarmTimes);
    cout << nextAlarmTime << endl;
    
    return 0;
}


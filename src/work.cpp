#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int start;
    int end;
};

int main() {
    // 读入任务列表
    int n;
    cin >> n;
    vector<Task> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].start >> tasks[i].end;
    }

    // 按照起始时间片排序
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.start < b.start;
    });

    int energy = 0;  // 总能耗
    int status = 0;  // 当前服务器状态，0: 空载，1: 单任务，2: 多任务
    int last_end = -1;  // 上一个任务结束时间片
    for (int i = 0; i < n; i++) {
        // 检查当前任务和上一个任务是否存在重叠
        if (tasks[i].start <= last_end) {
            // 存在重叠，服务器进入多任务状态
            if (status != 2) {
                energy += 4;
                status = 2;
            }
        } else {
            // 不存在重叠，服务器进入单任务状态或空载状态
            int duration = tasks[i].start - last_end;
            if (duration == 1 && status != 1) {
                energy += 3;
                status = 1;
            } else if (duration > 1) {
                energy += duration - 1;
                status = 0;
            }
        }
        // 更新上一个任务结束时间片
        last_end = tasks[i].end;
    }

    // 处理最后一个任务结束后的剩余时间片
    if (last_end < 1000000) {
        int duration = 1000000 - last_end;
        if (duration == 1 && status != 1) {
            energy += 3;
        } else if (duration > 1) {
            energy += duration - 1;
        }
    }

    // 输出总能耗
    cout << energy << endl;

    return 0;
}

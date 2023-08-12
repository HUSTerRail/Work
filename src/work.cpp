// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <unordered_set>
#include<bits/stdc++.h>
using namespace std;



int main() {
    int n, u, v;
    vector<int>w(n+1,0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];//权重
    }

 
    map<int, vector<int>>graph;
    vector<int>visited(n+1,0);

    while(cin >> u >>v){
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        for(int j=0; j<graph[i].size(); j++){
             if (!visited[i] &&  !visited[graph[i][j]] && w[i] == w[graph[i][j]]) {
                 result ++;
                 visited[i] = 1;
                 visited[graph[i][j]] = 1;
            }
        }
       
    }

    cout << result << endl;

    return 0;
}

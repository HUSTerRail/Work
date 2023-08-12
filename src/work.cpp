// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <unordered_set>
#include<bits/stdc++.h>
using namespace std;


bool find(int target, vector<bool>& used, vector<int>& match, vector<int>& w,map<int, vector<int>>&graph, int k){
    vector<int> neighbors = graph[k];
    for(int i = 0; i <neighbors.size(); i++){ //遍历每个偶数与奇数比较
            if(w[neighbors[i]] == w[target] &&  used[i] ==0){
                 used[i] = true;
                if(match[neighbors[i]] == 0 || find(match[neighbors[i]], used, match,w,graph,match[neighbors[i]])){ //如果第i个偶数还未配对，或者跟它配对的奇数还有别的选择
                    match[i] = target; //则配对该数
                    return true;
                }
            }
           
        
    }
    return false;
}

int main() {
    int n, u, v;
    vector<int>w(n+1,0);
    vector<int>match(n+1,0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];//权重
    }

 
    map<int, vector<int>>graph;
    vector<bool>visited(n+1,0);

    while(cin >> u >>v){
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // for(int i=0; i<2; i++){
    //     cin >> u >>v;
    //     graph[u].push_back(v);
    //     graph[v].push_back(u);
    // }

    int result = 0;
    // for (int i = 1; i <= n; i++) {
    //     for(int j=0; j<graph[i].size(); j++){
    //          if (!visited[i] &&  !visited[graph[i][j]] && w[i] == w[graph[i][j]]) {
    //              result += 2;
    //              visited[i] = 1;
    //              visited[graph[i][j]] = 1;
    //         }
    //     }
       
    // }
    for (int i = 1; i <= n; i++) {
        if(find(i, visited, match, w, graph, i)){
            result++;
        }
        // find(int target, vector<bool>& used, vector<int>& match, vector<int>& w,map<int, vector<int>>&graph, int k){
    }

    cout <<2* result << endl;

    return 0;
}

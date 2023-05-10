#include <bits.stdc++.h>
using namespace std;

const int MAXN = 105; // 服务节点总数的最大值
const int MAXM = 5005; // 服务间调用响应耗时或者服务自身计算耗时的最大值

struct Edge {
    int to; // 边的终点
    int cost; // 边的权值
    Edge(int t, int c) : to(t), cost(c) {}
};

vector<Edge> G[MAXN]; // 邻接表存图
int dist[MAXN]; // 源点到各个点的最短距离
bool vis[MAXN]; // 是否已经访问

// Dijkstra最短路径算法
void dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, false, sizeof(vis));
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(dist[s], s));
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].to;
            int w = G[u][i].cost;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    int u, v, w;
    for (int i = 0; i < n; i++) {
        cin >> u >> v >> w;
        G[u].push_back(Edge(v, w));
    }
    int s;
    cin >> s;
    dijkstra(s);
    int cnt = 0; // 可以实现染色的微服务个数
    int max_time = 0; // 全部完成染色的最短时间
    for (int i = 1; i <= m; i++) {
        if (dist[i] != 0x3f3f3f3f) {
            cnt++;
            max_time = max(max_time, dist[i]);
        }
    }
    cout << cnt << endl;
    cout << max_time << endl;
    return 0;
}

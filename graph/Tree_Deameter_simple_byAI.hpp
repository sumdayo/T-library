#include <bits/stdc++.h>
using namespace std;
#define ll long long


// https://github.com/sumdayo/T-library/tree/main/graphから参照（このライブラリはChat-gptを使用して作成した。）
#define INF (long long)2e18

// start から BFS
// {start から最も遠い頂点, 各頂点までの距離} を返す
pair<int, vector<ll>> bfs_farthest(
    const vector<vector<int>>& G,
    int start
) {
    int n = G.size();

    vector<ll> dist(n, INF);
    queue<int> que;

    dist[start] = 0;
    que.push(start);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int nex : G[v]) {
            if (dist[nex] > dist[v] + 1) {
                dist[nex] = dist[v] + 1;
                que.push(nex);
            }
        }
    }

    int farthest = start;

    for (int i = 0; i < n; i++) {
        if (dist[farthest] < dist[i]) {
            farthest = i;
        }
    }

    return {farthest, dist};
}


// 木の直径となるパスを返す
// 頂点番号は 0-indexed
vector<int> tree_diameter_path(
    const vector<vector<int>>& G
) {
    int n = G.size();

    // 適当な頂点0から最も遠い頂点 s を探す
    auto [s, dist1] = bfs_farthest(G, 0);

    // s から最も遠い頂点 t を探す
    // 同時に parent を記録してパスを復元する
    vector<ll> dist(n, INF);
    vector<int> parent(n, -1);
    queue<int> que;

    dist[s] = 0;
    que.push(s);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int nex : G[v]) {
            if (dist[nex] > dist[v] + 1) {
                dist[nex] = dist[v] + 1;
                parent[nex] = v;
                que.push(nex);
            }
        }
    }

    int t = s;

    for (int i = 0; i < n; i++) {
        if (dist[t] < dist[i]) {
            t = i;
        }
    }

    // t -> s と parent をたどる
    vector<int> path;

    for (int v = t; v != -1; v = parent[v]) {
        path.push_back(v);

        if (v == s) break;
    }

    // s -> t に直す
    reverse(path.begin(), path.end());

    return path;
}

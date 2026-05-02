#pragma once
#include <vector>

// 有向グラフのサイクル検出
// サイクルが存在すればtrueを返す。

bool cycle_detection(std::vector<std::vector<int>> &G) {
    int n = G.size();
    std::vector<bool> visited(n, false), finished(n, false);
    auto dfs=[&](auto dfs, int v) -> bool {
        if(visited[v]) return false;
        visited[v] = true;
        for(int e:G[v]) {
            if (finished[e]) continue;
            if (visited[e] || dfs(dfs, e)) return true;
        }
        finished[v] = true;
        return false;
    };

    for(int i=0;i<n;i++) if(dfs(dfs, i)) return true;

    return false;
}

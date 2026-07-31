#pragma once
#include <vector>
#include <string>
#include <algorithm>

template <typename T>
struct E {
    int to;
    T cost;
};
using GRAPH = vector<vector<E<long long>>>;

template <typename T>
pair<T, int> dfs(const GRAPH &graph, int v, int prv) {
    pair<T, int> res = {(T)0, v};
    for(auto &e : graph[v]) {
        if(e.to == prv) continue;
        auto nex = dfs<T>(graph, e.to, v);
        nex.first += e.cost;
        res = max(res, nex);
    }
    return res;
}

inline bool pathDfs(const GRAPH &graph, int v, int prv, int goal, vector<int> &path) {
    path.push_back(v);
    if(v == goal) return true;
    for(auto &e : graph[v]) {
        if(e.to == prv) continue;
        if(pathDfs(graph, e.to, v, goal, path)) return true;
    }
    path.pop_back();
    return false;
}

template <typename T>
T treeDiameter(GRAPH &graph) {
    pair<T, int> p1 = dfs<T>(graph, 0, -1);
    pair<T, int> p2 = dfs<T>(graph, p1.second, -1);
    return p2.first;
}

// 直径のコストと、その経路（頂点列）を返す
template <typename T>
pair<T, vector<int>> treeDiameterPath(GRAPH &graph) {
    pair<T, int> p1 = dfs<T>(graph, 0, -1);
    pair<T, int> p2 = dfs<T>(graph, p1.second, -1);
    vector<int> path;
    pathDfs(graph, p1.second, -1, p2.second, path);
    return {p2.first, path};
}


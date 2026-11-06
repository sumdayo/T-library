#pragma once

#include <vector>
#include <numeric>
#include <algorithm>


// 2026/11/06追記：覚えてないけど、以下のライブラリはAI使ったと思います。
// https://github.com/sumdayo/T-library/blob/main/graph/WeightedTreeCentroid.hppを参照
// 木の重心を求め、その頂点番号を返す。
struct WeightedTreeCentroid {
    int _n;
    const std::vector<std::vector<int>> &G;
    std::vector<long long> C;
    long long tot;
    int res;

    WeightedTreeCentroid(const std::vector<std::vector<int>>& graph, const std::vector<long long>& weights = {})
        : _n(graph.size()), G(graph), C(weights), tot(0), res(-1) {
        // 重みの指定がない場合、各頂点の重みを1とする
        if(!this->C.empty()) {
            for(long long e : this->C) tot += e;
        } else {
            tot = _n;
            this->C.assign(_n, 1);
        }
    }

    // 重心を求める（実際に探索を開始する）
    int find() {
        dfs(0, -1);
        return res;
    }

private:
    long long dfs(int v, int p) {
        long long cost = C[v];
        long long mx_weight = 0;

        for (int u : G[v]) {
            if (u == p) continue;
            long long child_weight = dfs(u, v);
            mx_weight = std::max(mx_weight, child_weight);
            cost += child_weight;
        }

        long long rest_weight = tot - cost;
        long long max_weight = std::max(mx_weight, rest_weight);
        
        // どの成分も全体の半分以下なら重心
        if (max_weight * 2 <= tot) res = v;

        // 親には部分木全体の重みを返す
        return cost;
    }
};

// ---使い方---
// 重心がない場合
// WeightedTreeCentroid centroid(G);
// int c = centroid.find();

// 重心がない場合
// vector<long long> weight(n);
// WeightedTreeCentroid centroid(G, weight);
// int c = centroid.find();
// ------------

#pragma once

#include <vector>g
#include <algorithm>

/**
 * @brief 動的な辺更新に対応したワーシャル・フロイド法
 * @tparam T 距離のデータ型 (e.g., long long)
 */
template<typename T>
struct DynamicWarshallFloyd {
    const int V;
    const T INF;
    std::vector<std::vector<T>> dist;

    DynamicWarshallFloyd(int n, T inf_val) : V(n), INF(inf_val), dist(V, std::vector<T>(V, INF)) {
        for(int i=0;i<V;i++) {
            dist[i][i] = 0;
        }
    }

    void add_edge(int u, int v, T cost, bool flag = false) {
        dist[u][v] = std::min(dist[u][v], cost);
        if(!flag) {
            dist[v][u] = std::min(dist[v][u], cost);
        }
    }

    void build() {
        for(int k=0;k<V;k++) {
            for(int i=0;i<V;i++) {
                for(int j=0;j<V;j++) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    void update(int u, int v, T cost) {
        if (cost >= dist[u][v]) return;

        dist[u][v] = cost;
        dist[v][u] = cost;

        for(int i=0;i<V;i++) {
            for(int j=0;j<V;j++) {
                // i -> u -> v -> j
                if (dist[i][u] != INF && dist[v][j] != INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][u] + cost + dist[v][j]);
                }
                // i -> v -> u -> j
                if (dist[i][v] != INF && dist[u][j] != INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][v] + cost + dist[u][j]);
                }
            }
        }
    }

    T get(int u, int v) const {
        return dist[u][v];
    }
};
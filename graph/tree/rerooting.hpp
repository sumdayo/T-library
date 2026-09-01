#include <bits/stdc++.h>
using namespace std;


// 全方位木DP
// ans[v] = add_vertex(vから出る全方向の寄与をopでまとめたもの, v )
// 未検証

// 問題ごとに書き換え
using S = pair<ll, ll>; // {部分木サイズ, 距離の和}
const S ID = {0, 0}; // opの単位元

S op(S a, S b) { // 兄弟方向をまとめる
    return {a.first + b.first, a.second + b.second};
}
S add_vertex(S x, int v) { // 頂点vを足す
    return {x.first + 1, x.second};
}
S add_edge(S x, int par, int chi) {
    return {x.first, x.second + x.first};
}
// ここまで書き換え

vector<S> rerooting(const vector<vector<int>>& G, int root = 0) {
    int n = G.size();
    vector<int> par(n, -1), ord;
    vector<S> down(n, ID), up(n, ID), ans(n, ID);

    vector<bool> vis(n, false);
    vector<int> st = {root};
    vis[root] = true;
    while (!st.empty()) {
        int v = st.back(); st.pop_back();
        ord.push_back(v);
        for (int u : G[v]) if (!vis[u]) {
            vis[u] = true;
            par[u] = v;
            st.push_back(u);
        }
    }

    // 1回目: 葉 → 根
    for (int i = n - 1; i >= 0; i--) {
        int v = ord[i];
        S acc = ID;
        for (int u : G[v]) if (u != par[v]) acc = op(acc, down[u]);
        S x = add_vertex(acc, v);
        if (par[v] == -1) down[v] = x;
        else down[v] = add_edge(x, par[v], v);
    }

    for (int i = 0; i < n; i++) {
        int v = ord[i];
        int k = G[v].size();

        // dir[j] = j 番目の隣に向かう方向の寄与
        vector<S> dir(k);
        for (int j = 0; j < k; j++) {
            int u = G[v][j];
            if (u == par[v]) dir[j] = up[v];
            else dir[j] = down[u];
        }

        // 左右からの累積
        vector<S> pre(k + 1, ID), suf(k + 1, ID);
        for (int j = 0; j < k; j++) pre[j + 1] = op(pre[j], dir[j]);
        for (int j = k - 1; j >= 0; j--) suf[j] = op(dir[j], suf[j + 1]);

        ans[v] = add_vertex(pre[k], v);

        for (int j = 0; j < k; j++) {
            int u = G[v][j];
            if (u == par[v]) continue;
            S rest = op(pre[j], suf[j + 1]);   // u 以外の全方向
            up[u] = add_edge(add_vertex(rest, v), v, u);
        }
    }
    return ans;
}


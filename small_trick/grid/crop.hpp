// crop.hpp — グリッドの外接矩形を切り出す（平行移動の正規化）
#pragma once
#include <bits/stdc++.h>
 
// bg 以外のマスを「図形」とみなし、それを囲む最小の長方形を返す
// 図形が空なら空のグリッドを返す
template <class G, class T>
G crop(const G& g, T bg) {
    int h = g.size(), w = h ? g[0].size() : 0;
    int ti = h, bi = -1, lj = w, rj = -1;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (!(g[i][j] == bg)) {
                ti = std::min(ti, i); bi = std::max(bi, i);
                lj = std::min(lj, j); rj = std::max(rj, j);
            }
    G c;
    for (int i = ti; i <= bi; i++)
        c.emplace_back(g[i].begin() + lj, g[i].begin() + rj + 1);
    return c;
}

// 文字グリッドの既定背景は'.'
inline std::vector<std::string> crop(const std::vector<std::string>& g) {
    return crop(g, '.');
}
// 数値グリッドの既定背景は0（相当）
template <class T>
std::vector<std::vector<T>> crop(const std::vector<std::vector<T>>& g) {
    return crop(g, T{});
}

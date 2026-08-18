#pragma once
#include <bits/stdc++.h>

// 巡回平行移動でaをbにできるか
template <class G>
bool same_shift(const G& a, const G& b) {
    int h = a.size(), w = h ? a[0].size() : 0;
    if ((int)b.size() != h || (h && (int)b[0].size() != w)) return false;
    for (int di = 0; di < h; di++) for (int dj = 0; dj < w; dj++) {
        bool ok = true;
        for (int i = 0; i < h && ok; i++)
            for (int j = 0; j < w; j++)
                if (a[i][j] != b[(i + di) % h][(j + dj) % w]) { ok = false; break; }
        if (ok) return true;
    }
    return false;
}

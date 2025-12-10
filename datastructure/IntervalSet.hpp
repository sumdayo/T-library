#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct IntervalSet {
    // pair<left, right> で管理 ([l, r))
    set<pair<T, T>> s;

    IntervalSet() {}

    // 区間 [l, r) を追加する (重なる区間はマージ)
    void insert(T l, T r) {
        if (l >= r) return;
        auto itr = s.upper_bound({l, numeric_limits<T>::min()});
        if (itr != s.begin()) itr--;

        while (itr != s.end()) {
            if (r < itr->first) break; // 重なりなし（右側）
            if (itr->second < l) {     // 重なりなし（左側）
                itr++;
                continue;
            }
            // 重なりがある場合、マージして削除
            l = min(l, itr->first);
            r = max(r, itr->second);
            itr = s.erase(itr);
        }
        s.insert({l, r});
    }

    // 区間 [l, r) を削除する (重なる部分を切り取る)
    // 戻り値: 実際に削除された区間の長さの合計
    T erase(T l, T r) {
        if (l >= r) return 0;
        T removed_len = 0;
        
        auto itr = s.upper_bound({l, numeric_limits<T>::min()});
        if (itr != s.begin()) itr--;

        while (itr != s.end()) {
            if (r <= itr->first) break; // 削除区間より右にあるので終了
            if (itr->second <= l) {     // 削除区間より左にあるので次へ
                itr++;
                continue;
            }

            T nl = itr->first;
            T nr = itr->second;
            itr = s.erase(itr);

            T overlap_l = max(l, nl);
            T overlap_r = min(r, nr);
            if (overlap_l < overlap_r) {
                removed_len += (overlap_r - overlap_l);
            }

            if (nl < l) {
                s.insert({nl, l});
            }
            if (nr > r) {
                s.insert({r, nr});
            }
        }
        return removed_len;
    }

    // 現在の区間の状態を出力（デバッグ用）
    void debug_IntervalSet() {
        for (auto p : s) cout << "[" << p.first << ", " << p.second << ") ";
        cout << endl;
    }
};
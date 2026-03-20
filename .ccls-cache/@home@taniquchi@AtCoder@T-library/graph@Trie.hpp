#pragma once
#include <vector>
#include <string>
#include <algorithm>

template <int char_size = 26>
struct Trie {
    std::vector<std::vector<int>> to;
    // end_cnt[v]: ノードvで終わる単語の数
    std::vector<int> end_cnt;

    Trie() {
        to.push_back(std::vector<int>(char_size, -1));
        end_cnt.push_back(0);
    }

    // 文字列の追加
    // 戻り値: 追加した単語の終端ノードID
    int add(const std::string& s) {
        int v = 0; // ルートから開始
        for (char c : s) {
            if (to[v][c - 'a'] == -1) {
                to[v][c - 'a'] = to.size();
                to.push_back(std::vector<int>(char_size, -1));
                end_cnt.push_back(0);
            }
            v = to[v][c - 'a'];
        }
        end_cnt[v]++; // 単語の終わりとしてカウント
        return v;
    }

    // 文字列の検索
    int count(const std::string& s) {
        int v = 0;
        for (char c : s) {
            if (to[v][c - 'a'] == -1) return 0; // 道がない
            v = to[v][c - 'a'];
        }
        return end_cnt[v];
    }

    // 接頭辞(Prefix)検索
    bool starts_with(const std::string& s) {
        int v = 0;
        for (char c : s) {
            if (to[v][c - 'a'] == -1) return false;
            v = to[v][c - 'a'];
        }
        return true;
    }
};
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

//
// 作成中。未完成
//

template <typename T = long long>
struct Trie {
    struct Node {
        std::vector<int> to;
        T cnt;
        // i番目の文字に対応する子ノードのインデックスを格納
        Node(): cnt(0) {
            // a-zを-1で初期化
            to.assign(26, -1);
        }
    };

    std::vector<Node> nodes;
    Trie(): nodes(1) {}
    
    void add(const std::string& s) {
        int v = 0;
        for(char c: s) {
            int char_idx = c - 'a';
            if(nodes[v].to[char_idx] == -1) {
                nodes[v].to[char_idx] = nodes.size();
                nodes.push_back(Node());
            }
            v = nodes[v].to[char_idx];
        }
        nodes[v].cnt++;
    }

    T ans;
    T dfs(T v) {
        T res = nodes[v].cnt;
        for(auto p: nodes[v].to) {
            res += dfs(p.second);
        }
        if(v>0) ans += ans * (long long)((res - 1) / 2);
        return res;
    }

    T solve() {
        ans = 0;
        dfs(0);
        return ans;
    }
};

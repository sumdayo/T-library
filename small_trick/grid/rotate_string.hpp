#pragma once
#include <bits/stdc++.h>
using namespace std;

// 未検証
vector<string> rotate_string(vector<string> s) {
    int sz = s.size();
    vector<string> res(sz, string(sz, '.'));
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            res[j][sz - i - 1] = s[i][j];
        }
    }
    return res;
}

#include <bits/stdc++.h>
using namespace std;

// mapで保持してループを回すよりも計算量が落ちる(おそらくO(nlogn) -> O(n)?)
// 必ず配列はあらかじめソートしておく。

long long samepaircalc(const vector<pair<long long, long long>> &vec) {
    long long res = (long long)0;
    int l = 0, sz = vec.size();
    while(l < sz) {
        int r = l;
        while(r < sz && vec[l] == vec[r]) r++;
        int num = r - l;
        res += num * (num - 1) / 2;
        l = r;
    }
    return res;
}
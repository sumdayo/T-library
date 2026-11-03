#include <bits/stdc++.h>
using namespace std;

// 最大増加部分列（LIS）
// A[i]を最後の要素とする最長増加部分列の長さを求める
template <typename T>
vector<int> LIS(vector<T> &A) {
    int N = A.size();
    long long INF = 1e9;
    vector<int> res(N, INF);
    vector<long long> dp;

    for(int i=0;i<N;i++) {
        vector<long long>::iterator itr;
        itr = lower_bound(dp.begin(), dp.end(), A[i]);
        int pos = itr - dp.begin();

        if(itr == dp.end()) {
            dp.push_back(A[i]);
        } else {
            // 同じ長さのlisの末尾をより小さい値に更新
            *itr = A[i];
        }
        // 現在までのlisの長さ
        res[i] = dp.size();
        // A[i]を末尾としたLISを求める場合は以下を採用する
        // res[i] = pos + 1;
    }
    return res;
}

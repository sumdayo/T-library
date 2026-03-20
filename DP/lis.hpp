#include <bits/stdc++.h>
using namespace std;

// 最大増加部分列（LIS）

template <typename T>
vector<T> LIS(vector<T> &A) {
    int N = A.size();
    long long INF = 1e18;
    vector<long long> res(N, INF);

    for(int i=0;i<N;i++) {
        vector<long long>::iterator itr;
        itr = lower_bound(res.begin(), res.end(), A[i]);
        *itr = A[i];
    }

    return res;
}

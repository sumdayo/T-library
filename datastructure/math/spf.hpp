#include<bits/stdc++.h>
using namespace std;


// 未検証
// 素因数分解をO(Q(log n))でできる
// 前計算でspf配列O(NlogN)で前計算しておく必要がある
// ここからペースト

const int MAX = 1001001;

template<typename T>
vector<T> smallest_prime_factors(T N) {
    vector<T> spf(N+1);

    for(T i = 0;i <= N;i++) {
        if (spf[i] == i) {
            for(T j = i * i;j <= N;j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    return spf;
}

template<typename T>
vector<T> factolization(T x, vector<T> &spf) {
    vector<T> ret;
    while(x != 1) {
        ret.push_back(spf[x]);
        x /= spf[x];
    }
    // 昇順にする必要がなければ以下のソートは不要
    sort(ret.begin(), ret.end());

    return ret;
}



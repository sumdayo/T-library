#include<bits/stdc++.h>
using namespace std;

// 素因数分解
// ここからペースト

vector<pair<long long, int>> pfact(long long num) {
    vector<pair<long long, int>> res;
    for (long long i = 2;i * i <= num;i++) {
        int cnt = 0;
        while (num % i == 0) {
            num /= i;
            cnt++;
        }
        if(cnt > 0) res.push_back({i, cnt});
    }
    if (num != 1) res.push_back({num, 1});

    return res;
}


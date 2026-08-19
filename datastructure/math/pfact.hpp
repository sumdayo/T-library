#include<bits/stdc++.h>
using namespace std;


// 未検証
// 素因数分解
// ここからペースト

vector<int> pfact(int num){
    vector<int> res;
    for (int i = 2;i * i <= num;i++) {
        while (num % i == 0) {
            num /= i;
            res.push_back(i);
        }
    }
    if (num != 1) res.push_back(num);

    return res;
}

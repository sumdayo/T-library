#include <bits/stdc++.h>
using namespace std;
#include <ext/rope>
using namespace __gnu_cxx;

// 任意の箇所に要素の挿入、および削除がO(logn)で可能。（ランダムアクセス）

template<typename T>
void print(const rope<T> &v) {
    for (T a : v) {
        cout << a << " ";
    }
    cout << '\n';
}

int main() {
    rope<int> v;
    int num = 3;
    v.insert(0, num); // 0番目にnumを挿入
    print(v);
    return 0;
}


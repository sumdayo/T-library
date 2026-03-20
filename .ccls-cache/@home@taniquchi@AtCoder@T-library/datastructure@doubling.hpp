#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

const int D = 60;

struct Doubling {
    int n;
    vector<vector<int>> to;

    Doubling(int n, vector<int>& a) : n(n), to(D, vector<int>(n)) {
        rep(i, n) to[0][i] = a[i];
        rep(i, D-1) rep(j, n) to[i+1][j] = to[i][to[i][j]];
    }

    int query(int x, long long y) {
        for (long long j = 0; j < D; j++) {
            if ((y >> j) & 1) {
                x = to[j][x];
            }
        }
        return x;
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }

    Doubling db(n, a);

    rep(i, q) {
        int x;
        long long y;
        cin >> x >> y;
        x--;
        cout << db.query(x, y) + 1 << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a) (a).begin(), (a).end()

int main() {
    ll n, ans = 0;
    cin >> n;
    vector<int> x(n);
    vector<ll> c(n);
    rep(i, n) {
        cin >> x[i];
        x[i]--;
    }

    rep(i, n) {
        cin >> c[i];
    }

    //0 -> 未訪問な頂点, 1 -> まさに計算中である頂点, 2 -> 計算が終わっている
    vector<int> state(n);
    for(int i=0;i<n;i++) {
        if(state[i] != 0) continue;
        int v = i;
        vector<int> vs;
        auto dfs = [&](auto dfs, int v) -> int {
            if(state[v] == 2) return -1;
            if(state[v] == 1) return v;
            state[v] = 1;
            int r = dfs(dfs, x[v]);
            state[v] = 2;
            if(r == -1) return -1;
            vs.push_back(v);
            if(r == v) return -1;
            return r;
        };
        dfs(dfs, i);
        if(vs.size()) {
            ll mi = 1e15;
            for(int v : vs) mi = min(mi, c[v]);
            ans += mi;
        }
    }
    cout << ans << endl;
    return 0;
}

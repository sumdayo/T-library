#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
//-------------------------------
/*
 * 二項係数の関数
 * コピペするなら以下からになると思う。
*/

using mint = atcoder::modint998244353;

const int MX = 510100;
mint fac[MX], facinv[MX], inv[MX];

void comCalc() { //nCrを前計算する
    const int MOD = mint::mod();
    fac[0] = fac[1] = 1;
    facinv[0] = facinv[1] = 1;
    inv[1] = 1;
    for(int i=2;i<MX;i++){
        fac[i] = fac[i-1] * i;
        inv[i] = (-1) * inv[MOD%i] * (MOD/i);
        facinv[i] = facinv[i-1] * inv[i];
    }
}

 //nCrを出力
mint comb(int n, int k) { //nCrを出力
    if(n<k || n<0 || k<0) return 0;
    return fac[n] * facinv[k] * facinv[n-k];
}

// n種類のものからk個を、重複を許して選ぶ場合の数
// n個の箱にk個の区別できない玉を入れる場合の数ともいえる
mint h(int k, int n) {
    return comb(n+k-1, k);
}

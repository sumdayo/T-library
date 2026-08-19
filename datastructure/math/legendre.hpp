// ルジャンドルの公式
// N! が素数 P で何回割り切れるか（= v_P(N!)）を返す
//   v_P(N!) = floor(N/P) + floor(N/P^2) + floor(N/P^3) + ...
// 制約: N >= 0, P >= 2
// 計算量: O(log_P N)
// 用例: N! の末尾の 0 の個数 → legendre(N, 5)
long long legendre(long long N, long long P) {
    if (N == 0) return 0;
    long long res = 0;
    while (N > 0) {
        N /= P;
        res += N;
    }
    return res;
}

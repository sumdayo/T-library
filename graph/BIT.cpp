#include<vector>
template<typename T>
struct BIT {
    int N;
    vector<T> bit;
    BIT(int _N=0) :N(_N), bit(_N) {}
    void add(int i, T a) {
        i++;
        for (int j = i;j <= N;j += (j & -j)) {
            bit[j-1] += a;
        }
    }
    T sum(int i) {
        T sm = 0;
        for (int j = i;j > 0;j -= (j & -j)) {
            sm += bit[j-1];
        }
        return sm;
    }
    int lower_bound(T k) {
        if(k <= 0) return 0;
        int x = 0, i = 1;
        while((i<<1) <= N) i <<= 1;
        for(int j=i;j;j>>=1) {
            if(x + j <= N && bit[x+j-1] < k) {
                k -= bit[x-1];
                x += j;
            }
        }
        return x + 1;
    }
};

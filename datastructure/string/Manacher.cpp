#include <bits/stdc++.h>
using namespace std;

vector<int> manacher(string s) {
    vector<int> res(s.size());
    int l = 0, r = 0;
    while(l < s.size()) {
        while(l-r>=0 && l+r<s.size() && s[l-r] == s[l+r]) {
            r++;
        }
        res[l] = r;
        int k = 1;
        while(l-k>=0 && l+k<s.size() && k+res[l-k]<r) {
            res[l+k] = res[l-k];
            k++;
        }
        l += k;
    }
    return res;
};

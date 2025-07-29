#include <bits/stdc++.h>
using namespace std;

//-------------------------------
/*
 * 回文の判定(O(n))
 * コピペするなら以下からになると思う。
*/

bool isPalindrome(string s) {
    string ns = s;
    reverse(ns.begin(), ns.end());
    return (s == ns);
}
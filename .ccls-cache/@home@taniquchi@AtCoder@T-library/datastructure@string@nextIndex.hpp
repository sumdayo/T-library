#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// けんちょんさんのString/next.cppを参考
// res[i][j] i番目以降で最初に文字jが登場する場所が分かる。
vector<vector<int>> nextIndex(string &str) {
	int n = str.size();
	vector<vector<int>> res(n+1, vector<int>(26, n+1));
	for(int i=n;i>0;i--) {
		for(int j=0;j<26;j++) {
			res[i-1][j] = res[i][j];
		}
		int idx = str[i-1] - 'a';
		res[i-1][idx] = i-1;
	}
	return res;
}

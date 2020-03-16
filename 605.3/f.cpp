#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s, t;
	cin >> s >> t;
	int N = 202;

	int dp[s.length() + 1][t.length() + 1][N]; // i, j deal with number of elements matched by current string
	pair<pair<int, int>, pair<int, char>> store[s.length() + 1][t.length() + 1][N]; // stores previous info

	for(int i = 0; i < s.length()+ 1; i++)
		for (int j = 0; j < t.length() + 1; j++)
			for (int k = 0; k < N;++k)
				dp[i][j][k] = INF;

	dp[0][0][0] = 0;

	// let us now fill dp
	for(int i = 0; i < s.length() + 1; i++)
		for (int j = 0; j < t.length() + 1; j++)
			for (int k = 0; k < N;++k) {
				if (dp[i][j][k] == INF) continue;

				// deal with adding '(' to our string
				int next_i = i + ((i + 1) <= s.length() && s[i] == '(');
				int next_j = j + ((j + 1) <= t.length() && t[j] == '(');

				// update balance of next i. k + 1 as balance increases as we add (
				if (k + 1 < N && dp[next_i][next_j][k + 1] > dp[i][j][k] + 1) {
					dp[next_i][next_j][k + 1] = dp[i][j][k] + 1;
					store[next_i][next_j][k + 1] = make_pair(make_pair(i, j), make_pair(k, '('));
				}

				// deal with adding '(' to our string
				next_i = i + ((i + 1) <=s.length() && s[i] == ')');
				next_j = j + ((j + 1) <=t.length() && t[j] == ')');

				// update balance of next i. k - 1 as balance increases as we add )
				if (k - 1 >= 0 && dp[next_i][next_j][k - 1] > dp[i][j][k] + 1) {
					dp[next_i][next_j][k - 1] = dp[i][j][k] + 1;
					store[next_i][next_j][k - 1] = make_pair(make_pair(i, j), make_pair(k, ')'));
				}

			}

	// we have a bunch of balances that match with dp[s.length()][t.length()][bal]
	// let us find the minimum one

	int cbal = 0;
	for (int i = 0; i < N; ++i) {
		if (dp[s.length()][t.length()][i] + i < dp[s.length()][t.length()][cbal] + cbal)
			cbal = i;
	}

	// we are done we just need to construct the string
	string res = string(cbal, ')'); // remember the balance should be 0 for it to be regular string
	int i = s.length(), j = t.length(), k = cbal;

	while (i > 0 || j > 0 || k > 0) {
		res += store[i][j][k].second.second;
		int ni = store[i][j][k].first.first;
		int nk = store[i][j][k].second.first;
		int nj = store[i][j][k].first.second;

		i = ni; k = nk; j = nj;
	}

	reverse(res.begin(), res.end());
	cout << res;

	return 0;
}


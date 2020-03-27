#include <bits/stdc++.h>
using namespace std;

int n, h, l, r;
int dp[3000][3000]; // where dp[i][x] is the max number of good times If dude woke up at time x on day i - 1

int is_good(int j) {
	return (l <= j && j <= r);
}

int solve(int sleep_time, int i, int j) {
	int res = is_good(sleep_time);
	int next = i + 1;

	if (next < n)
		res += dp[next][sleep_time];

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> h >> l >> r;

	int a[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	memset(dp, 0, sizeof(dp));

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < h; j++) {
			int first = (j + a[i]), second = (j + a[i] - 1);
			dp[i][j] = max(solve(first % h, i, j), solve(second % h, i, j));
		}
	}

	cout << dp[0][0];

	return 0;
}

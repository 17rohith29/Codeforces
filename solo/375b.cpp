#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	string x;
	int n, m;
	cin >> n >> m;

	int arr[n][m];
	int dp[n][m];
	memset(arr, 0, sizeof(arr));
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n; ++i) {
		cin >> x;
		for (int j = 0; j < x.size(); j++)
			arr[i][j] = (x[j] - '0');
	}

	// let us now fill the dp
	for (int row = 0; row < n; ++row) {
		for (int col = m - 1; col >= 0; col--) {
			if (col == m - 1)
				dp[row][col] = arr[row][col];
			else if (arr[row][col] == 1) {
				dp[row][col] = 1 + dp[row][col + 1];
			} else {
				dp[row][col] = 0;
			}
		}
	}

	long long ans = 0;

	for (int col = 0; col < m; ++col) {
		int store[n];
		for (int i = 0; i < n; ++i)
			store[i] = dp[i][col];

		sort(store, store + n);
		for (int i = 0; i < n; ++i) {
			long long val = store[i];
			long long num_elts_greater = n - i;
			ans = max(ans, val * num_elts_greater);
		}
	}

	cout << ans;

	return 0;
}


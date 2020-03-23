#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[n + 1];

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	// first let us find the segments that can be compressed to 1 value
	int comp[n+1][n + 1];

	// initial setup
	memset(comp, -1, sizeof(comp));

	for (int i = n; i >= 0; i--) {
		for (int j = i; j <= n; j++) {
			if (i == j) { comp[i][j] = a[i]; continue; }

			for (int k = i; k < j; k++) {
				 if (comp[i][k] == comp[k + 1][j] && comp[i][k] != -1)
					 comp[i][j] = comp[i][k] + 1;
			}
		}
	}

	int dp[n + 1];
	for (int i = 1; i <= n; i++) dp[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (comp[j][i] != -1) {
				if (j == 1) dp[i] = 1;
				else dp[i] = min(dp[i], dp[j - 1]+ 1);
			}
		}
	}

	cout << dp[n];
	return 0;
}


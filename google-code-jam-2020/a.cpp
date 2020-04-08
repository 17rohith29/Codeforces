#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cse = 1;
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int a[n][n];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> a[i][j];

		long long trace = 0;
		for (int i = 0; i < n; ++i)
			trace += a[i][i];

		int row = 0, col = 0;
		int arr[n];
		for (int i = 0; i < n; ++i) {
			memset(arr, 0, sizeof(arr));
			for (int j = 0; j < n; j++) {
				arr[a[i][j] - 1]++;
				if (arr[a[i][j] - 1] > 1) {
					row++;
					break;
				}
			}
			memset(arr, 0, sizeof(arr));
			for (int j = 0; j < n; j++) {
				arr[a[j][i] - 1]++;
				if (arr[a[j][i] - 1] > 1) {
					col++;
					break;
				}
			}
		}

		printf("Case #%d: %lld %d %d", cse++, trace, row, col);
		cout << endl;
	}
	fflush(stdout);

	return 0;
}


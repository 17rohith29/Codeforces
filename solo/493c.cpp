#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;

	long long a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	cin >> m;
	long long b[m];
	for (int i = 0; i < m; ++i)
		cin >> b[i];

	long long ans = LLONG_MIN, A = 0LL, B = 0LL;
	sort(a, a + n);
	sort(b, b + m);

	for (int i = n - 1; i >= -1; --i) {
		// anything greater than or equal to x is 3 points
		long long score_a, score_b, cur;

		if (i >= 0) {
			score_a = 2 * i + 3 * (n - i);
			int ptr_b = distance(b, lower_bound(b, b + m, a[i]));
			score_b = 2 * ptr_b + 3 * (m - ptr_b);

			cur = score_a - score_b;
		} else if (i == -1) {
			score_a = 2 * n;
			score_b = 2 * m;
			cur = n * 2 - m * 2;
		}

		if (ans < cur || (ans == cur && score_a > A)) {
			A = score_a;
			B = score_b;
			ans = cur;
		}
	}

	cout << A << ":" << B;

	return 0;
}


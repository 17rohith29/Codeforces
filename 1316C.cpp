#include <bits/stdc++.h>
using namespace std;

int main() {

	long long n, m, p, ans = -1;
	cin >> n >> m >> p;
	string temp;
	long long c, d = -1;
	for (long long i = 0; i < n; ++i) {
		cin >> c;
		if (c % p != 0) {
			d = i;
			if (i != n - 1)
				getline(cin, temp);
			break;
		}
	}

	for (long long i = 0; i < m; ++i) {
		cin >> c;
		if (c % p != 0) {
			ans = i;
			if (i != m - 1)
				getline(cin, temp);
			break;
		}
	}

	cout << ans + d;
	return 0;
}

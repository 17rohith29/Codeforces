#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	long long b[n + 5], a[n + 5];
	long long max_prev = 0;

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	a[1] = b[1];
	max_prev = max(a[1], 0LL);

	for (int i = 2; i <= n; i++) {
		a[i] = b[i] + max_prev;
		max_prev = max(max_prev, a[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (i != 1)
			cout << " ";
		cout << a[i];
	}

	return 0;
}


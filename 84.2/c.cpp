#include <bits/stdc++.h>
using namespace std;

void add(int n, char x, string &p) {
	for (int i = 0; i < n; i++)
		p += x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	int x;

	for (int i = 0; i < k; i++) {
		cin >> x;
		cin >> x;
	}

	for (int i = 0; i < k; i++) {
		cin >> x;
		cin >> x;
	}

	string res = "";
	add(n - 1, 'U', res);
	add(m - 1, 'L', res);

	int right = 1;
	for (int i = 0; i < n; i++) {
		if (right) {
			add(m - 1, 'R', res);
			right = 0;
		} else {
			add(m - 1, 'L', res);
			right = 1;
		}

		if (i != n - 1)
		add (1, 'D', res);
	}

	if (res.size() >= 2 * m * n)
		cout << -1;
	else {
	cout << res.size() << endl;
	cout << res;
	}

	return 0;
}


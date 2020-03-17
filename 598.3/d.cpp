#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, d;
	cin >> n >> m >> d;
	int c[m];
	int r[n + 1];
	for (int i = 0; i < n + 1; ++i) r[i] = 0;
	int sum = 0;
	for (int i = 0; i < m; ++i) {
		cin >> c[i];
		sum += c[i];
	}
	int last_jump = 0;
	int count = 1;
	for (int x : c) {
		int rem = sum - x; // want rem amt of space for rem tiles
		int last_pos = n - rem - (x - 1);
		int first = min(last_pos, last_jump + d);
		last_jump = first + x - 1;
		sum -= x;

		for (int i = 0; i < x; i++) {
			r[i + first] = count;
		}
		count++;
	}

	if (n +1 - last_jump <= d) {
	cout << "YES" << endl;
	for(int i = 1; i < n + 1; i++) {
		if (i != 1) cout << " ";
		cout << r[i];
	}
	} else cout << "NO" << endl;

	return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;

	while (q--) {
		int n;
		cin >> n;
		int a[n];
		int b[n];

		for(int i =0; i < n; ++i) {
			cin >> a[i];
			b[i] = 0;
		}

		for (int i = n - 2; i >= 0; i--) {
			if (a[i] > a[i + 1]) {
				int x = a[i + 1];
				a[i + 1] = a[i];
				a[i] = x;
				b[i] = 1;

				for (int k = i + 1; k < n - 1; ++k) {
					if (b[k] == 1) break;
					else if (a[k] > a[k + 1]) {
						int y = a[k + 1];
						a[k + 1] = a[k];
						a[k] = y;
						b[k] = 1;
					} else break;
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			if (i != 0) cout << " ";
			cout << a[i];
		}

		if (q) cout << endl;
	}

	return 0;
}


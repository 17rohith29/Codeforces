#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	int n;
	cin >> t;

	while (t--) {
		cin >> n;
		if (n == 1)
			cout << -1;
		else {
			int x = n - 1;
			bool four = false;
			if (x % 3 == 0) {
				four = true;
			}

			if (four) {
				x--;
				cout << 4;
			}

			for (int i = 0; i < x; i++) {
				cout << 2;
			}

			cout << 3;
		}

		if (t)
			cout << endl;
	}

	return 0;
}

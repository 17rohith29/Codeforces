#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n;

	cin >> t;

	while (t--) {
		cin >> n;
		int a[n];

		for(int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a + n, greater<>());
		for (int i =0 ; i < n; i++) {
			if (i != 0) cout << " ";
			cout << a[i];
		}

		if (t) cout << endl;
	}

	return 0;
}


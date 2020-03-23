#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, m, n;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		if (n % m == 0) {
			cout << "YES";
		} else
			cout << "NO";
		if (t)
			cout << endl;
	}

	return 0;
}


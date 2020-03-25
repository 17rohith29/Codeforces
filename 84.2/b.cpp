#include <bits/stdc++.h>
using namespace std;

int INF = 1e5 + 10;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n; cin >> n;
		int used[n + 1];
		int matched[n + 1];
		memset(used, 0, sizeof(used));
		memset(matched, 0, sizeof(matched));

		for (int i = 0; i < n; i++) {
			int min = INF;
			int k, cur;
			cin >> k;

			for (int j = 1; j <= k; j++) {
				cin >> cur;
				if (cur < min) {
					if (used[cur]) continue;
					else {
						min = cur;
					}
				}
			}

			if (min != INF) {
				used[min] = 1;
				matched[i + 1] = 1;
			}
		}

		if (count(matched, matched + n + 1, 1) == n)
			cout << "OPTIMAL";
		else {
			int k = 1;
			while (matched[k] == 1)
				k++;
			int num = 1;
			while (used[num] == 1)
				num++;
			cout << "IMPROVE" << endl;
			cout << k << " " << num;
		}

		if (t) cout << endl;
	}

	return 0;
}


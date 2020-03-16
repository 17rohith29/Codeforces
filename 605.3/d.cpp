#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int arr[n];
	int res[n][2];

	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
		res[i][0] = 1;
		res[i][1] = 1;
	}

	for (int i = n - 1; i >= 0; i--) {
		// continue onword adding next element
		if (i +1 < n && arr[i + 1] > arr[i])
			res[i][0] = 1 + res[i + 1][0];

		// drop next element
		if (i + 2 < n && arr[i + 2] > arr[i])
			res[i][1] = 1 + res[i + 2][0];

		// go on with next element with its dropping
		if (i + 1 < n && arr[i + 1] > arr[i])
			res[i][1] = max(res[i][1], 1 + res[i + 1][1]);
	}

	int mx = 1;
	for(int i =0; i < n; ++i) {
		mx = max(mx, res[i][0]);
		mx = max(mx, res[i][1]);
	}

	cout << mx;


	return 0;
}


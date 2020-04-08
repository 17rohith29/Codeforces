#include <bits/stdc++.h>
using namespace std;
int t, b;
vector<int> arr;
int left, right, ctr;

void help() {
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t >> b;
	arr.resize(b);


	while (t--) {
		fill(arr.begin(), arr.end(), -1);
		// start from both sides
		ctr = 0;
		left = 1, right = b;
		bool lefts = true;

		while (left <= right) {

			if (ctr + 1!= 1 && (ctr + 1) % 10 == 1) {
				// lets send something else
				help();
			} else {
				if (lefts)
					cout << left << endl;
				else
					cout << right << endl;
				ctr++;
				int ans; cin >> ans;
				if (lefts)
					b[left++ - 1] = ans;
				else
					b[right-- - 1] = ans;

				lefts = !lefts;
			}
		}

		for (int x : b)
			cout << x;
		cout << endl;
	}

	return 0;
}


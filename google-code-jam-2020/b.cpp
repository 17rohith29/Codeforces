#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	string s;
	cin >> t;

	for (int i = 1; i <= t; ++i) {
		cin >> s;
		string r = "";
		for (char x : s)
			r += x;
		int n = s.length();
		int before[n], after[n];
		memset(before, 0, sizeof(before));
		memset(after, 0, sizeof(before));

		for (int j = 9; j >= 1; j--) {
			for (int k = 0; k < r.length(); k++) {
				if (r[k] == ('0' + j)) {
					int end = k;
					while (end + 1 < r.length() && r[end + 1] == r[end])
						end++;

					for (int m = k; m <= end; m++) {
						r[m] = r[m] - 1;
					}

					before[k]++;
					after[end]++;
					k = end;
				}
			}
		}

		string res = "";
		for (int j = 0; j < s.length(); j++) {
			for (int z = 0; z < before[j]; z++)
				res += '(';
			res += s[j];
			for (int z = 0; z < after[j]; z++)
				res += ')';
		}

		cout << "Case #" << i << ": " << res << endl;
	}

	return 0;
}


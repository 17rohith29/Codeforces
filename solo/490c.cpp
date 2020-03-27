#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string key, res_a, res_b;
	long long a, b, x = 0, y = 0;
	bool pos = false;

	cin >> key >> a >> b;
	int length_a = to_string(a).size();

	if (key.size() >= length_a + 1 && key[0] != '0') {
		for(int i = 0; i < length_a; i++) {
			x = (x * 10+ (key[i] - '0')) % a;
		}
		for(int i = length_a; i < key.length(); i++) {
			y = (y * 10+ (key[i] - '0')) % b;
		}

		vector<long long> dp(key.size());
		int ten = 1;

		for (int i = key.size() - 1; i >= 0; i--) {
			int cur = key[i] - '0';
			dp[i] = (cur * ten) % b;
			ten = (ten * 10) % b;
		}

		for (int i = length_a - 1; i < key.length() - 1; i++) {
			int cur = key[i] - '0';
			if (i != length_a - 1) {
				x = (x * 10 + cur) % a;
				y = (y - dp[i]) % b;
			}

			if (x % a == 0 && y % b == 0 && (key[i + 1]) != '0') {
				pos = true;
				res_a = key.substr(0, i + 1);
				res_b = key.substr(i + 1, key.length() - (i + 1));
				break;
			}
		}
	}

	if (pos) {
		cout << "YES" << endl << res_a << endl << res_b;
	} else {
		cout << "NO";
	}
	return 0;
}


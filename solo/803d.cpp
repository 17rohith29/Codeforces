#include <bits/stdc++.h>
using namespace std;

int k;
char total[1000005];
string ttl;
vector<string> s;

bool solve(int max_w) {
	int line_used = 1;
	int width = 0;
	for (int i = 0; i < s.size(); ++i) {
		int add = s[i].length() + (i != s.size() - 1);
		if (add > max_w) return false;

		if (width + add > max_w) {
			line_used++;
			width = add;
		} else {
			width += add;
		}
	}

	return line_used <= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	cin.getline(total,1000005);
	cin.getline(total,1000005);

	ttl = total;

	for (int i = 0; i < ttl.length(); i++) {
		if (ttl[i] == '-') {
			ttl[i] = ' ';
			total[i] = ' ';
		}
	}

	char* tok = strtok(total, " ");
	while (tok != NULL) {
		s.push_back(tok);
		tok = strtok(NULL, " ");
	}

	int min = 1, high = ttl.length();
	int ans = high;
	// we want the minimum possible ans
	while (min <= high) {
		int mid = ((high + min) / 2);

		if (solve(mid)) {
			ans = std::min(ans, mid);
			high = mid - 1;
		} else {
			min = mid + 1;
		}
	}

	cout << ans;

	return 0;
}


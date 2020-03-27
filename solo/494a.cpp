#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	vector<int> res;
	bool pos = true;
	int a = 0;

	for (char x : s) {
		if (x == '(')
			a++;
		else if (x == ')')
			a--;
		else {
			res.push_back(1);
			a--;
		}

		if (a < 0) {
			pos = false;
			break;
		}
	}

	if (pos && a > 0) {
		res[res.size() - 1] += a;
	}

	a = 0;
	int index = 0;
	for (char x : s) {
		if (x == '(')
			a++;
		else if (x == ')')
			a--;
		else {
			a -= res[index++];
		}

		if (a < 0) {
			pos = false;
			break;
		}
	}

	if (!pos) cout << -1;
	else {
		for (int x : res) cout << x << endl;
	}
	return 0;
}

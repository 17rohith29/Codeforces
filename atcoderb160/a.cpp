#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	bool d = false;

	if (s.length() >= 6)
		if (s[2] == s[3] && s[4] == s[5])
			d = true;

	if (d)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}


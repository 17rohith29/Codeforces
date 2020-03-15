#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	string s;
	int res = 0;
	cin >> x >> s;

	while(s.length() != 0) {
		string::iterator max = s.end();
		for(auto it = s.begin(); it != s.end(); ++it) {
			// can we remove it
			if (it != s.begin()) {
				char cur = *it, next = *(it -1);
				if (cur - next == 1)
					if (max == s.end() || *max < *it)
						max = it;
			}if (it != s.end() - 1) {
				char cur = *it, next = *(it + 1);
				if (cur - next == 1)
					if (max == s.end() || *max < *it)
						max = it;
			}
		}

		if (max == s.end())
			break;
		else {
			s.erase(max);
			res++;
		}
	}

	cout << res;
}
